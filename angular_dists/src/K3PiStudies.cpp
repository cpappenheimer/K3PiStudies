// Use this code to look at mass and angular distributions for either data/full MC or toy MC.
// Running code over data/full MC applies cuts and generates additional plots showing cuts and more kinematics.
// Running code over toy MC generates plots showing mass/angular distributions only.
// WARNING !!! This code was never tested on data/full MC !!!

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <utility>
#include <limits>
#include <map>

#include <CLI/CLI.hpp>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

// #include <LHCbStyle/lhcbStyle.h>

#include <TFile.h>
#include <TTreeReaderValue.h>
#include <TTreeReader.h>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TLegend.h>
#include <TPaveText.h>

#include "K3PiStudiesUtils.h"
#include "K3PiStudiesHists.h"
#include "K3PiStudies.h"

namespace K3PiStudies
{

	const double K3PiStudies::_D0_LIFETIME_CUT_PS = K3PiStudiesUtils::_D0_LIFETIME_PS;

	void printSummary(
		int numEvents,
		int numEventsPassingCuts,
		const std::pair<double, double> &decayTimeLimits_ps)
	{
		double lowerBinEdge_ps = decayTimeLimits_ps.first;
		double upperBinEdge_ps = decayTimeLimits_ps.second;

		std::cout << "For decay time bin: " << K3PiStudiesUtils::d0TimeBinToString(decayTimeLimits_ps, "ps") << std::endl;
		std::cout << "Processed " << numEvents << " events." << std::endl;
		std::cout << numEventsPassingCuts << " events were in this decay time bin and passed cuts." << std::endl;
	}

	Phsp4Body addEntryToCommonHists(CommonHistsWithKinematics &commonHists,
									bool _IS_D0,
									const TLorentzVector &_pD0_IN_D0CM_MEV,
									const TLorentzVector &kminus_in_D0_CM_MeV,
									const TLorentzVector &piPlus1_in_D0_CM_MeV,
									const TLorentzVector &piPlus2_in_D0_CM_MeV,
									const TLorentzVector &piMinus_in_D0_CM_MeV,
									bool printSanityChecks,
									int eventNum,
									bool verifyAngles,
									double d0Mass_MeV,
									double deltaM_MeV,
									double d0DecayTime_ps)
	{
		std::string evtStr = std::to_string(eventNum);

		commonHists.allMD0Hist->Fill(d0Mass_MeV);
		commonHists.allDeltaMHist->Fill(deltaM_MeV);
		commonHists.allMD0VDeltaMHist->Fill(d0Mass_MeV, deltaM_MeV);
		if (_IS_D0)
		{
			commonHists.d0OnlyMD0Hist->Fill(d0Mass_MeV);
		}
		else
		{
			commonHists.d0BarOnlyMD0Hist->Fill(d0Mass_MeV);
		}

		commonHists.d0DecayTOverTau->Fill(d0DecayTime_ps / K3PiStudiesUtils::_D0_LIFETIME_PS);

		//  The second step is to choose which pi+ to associate with the K- (or CC). We will
		//  discriminate on the basis of (K,pi) invariant mass.
		//  Once the choice of pairs is made, define tracks (a), (b), (c), (d) and create
		//  their four-vectors in the D0 CM.  From these, extract the three-vectors
		//  and calculate the sine of the angle between the (K-.pi+) plane and the (pi-,pi+) plane

		TLorentzVector _pA_IN_D0CM_MEV = kminus_in_D0_CM_MeV;  // K-
		TLorentzVector _pB_IN_D0CM_MEV;						   // pi+ that forms lowest (K, pi+) invariant mass
		TLorentzVector _pC_IN_D0CM_MEV = piMinus_in_D0_CM_MeV; // pi-
		TLorentzVector _pD_IN_D0CM_MEV;						   // the other pi+
		if (K3PiStudiesUtils::isKPi1LowerMassPair(kminus_in_D0_CM_MeV, piPlus1_in_D0_CM_MeV, piPlus2_in_D0_CM_MeV))
		{
			_pB_IN_D0CM_MEV = piPlus1_in_D0_CM_MeV;
			_pD_IN_D0CM_MEV = piPlus2_in_D0_CM_MeV;
		}
		else
		{
			_pB_IN_D0CM_MEV = piPlus2_in_D0_CM_MeV;
			_pD_IN_D0CM_MEV = piPlus1_in_D0_CM_MeV;
		}

		TLorentzVector pAD_in_D0CM_MeV = _pA_IN_D0CM_MEV + _pD_IN_D0CM_MEV;
		TLorentzVector pCB_in_D0CM_MeV = _pC_IN_D0CM_MEV + _pB_IN_D0CM_MEV;
		TLorentzVector pABD_in_D0CM_MeV = _pA_IN_D0CM_MEV + _pB_IN_D0CM_MEV + _pD_IN_D0CM_MEV;

		double piMinusEnergy = _pC_IN_D0CM_MEV.E();
		commonHists.piMinusEnergyHist->Fill(piMinusEnergy);
		commonHists.KMinusEnergyHist->Fill(_pA_IN_D0CM_MEV.E());
		commonHists.piPlusBEnergyHist->Fill(_pB_IN_D0CM_MEV.E());
		commonHists.piPlusDEnergyHist->Fill(_pD_IN_D0CM_MEV.E());
		commonHists.KPiPiMassSqHist->Fill(pABD_in_D0CM_MeV.M() * pABD_in_D0CM_MeV.M() / 1000000.); // /1000000 to get GeV**2

		if (_IS_D0)
		{
			commonHists.piMinusEnergyHistD0->Fill(piMinusEnergy);
			commonHists.KMinusEnergyHistD0->Fill(_pA_IN_D0CM_MEV.E());
			commonHists.piPlusBEnergyHistD0->Fill(_pB_IN_D0CM_MEV.E());
			commonHists.piPlusDEnergyHistD0->Fill(_pD_IN_D0CM_MEV.E());
		}
		else
		{
			commonHists.piMinusEnergyHistD0bar->Fill(piMinusEnergy);
			commonHists.KMinusEnergyHistD0bar->Fill(_pA_IN_D0CM_MEV.E());
			commonHists.piPlusBEnergyHistD0bar->Fill(_pB_IN_D0CM_MEV.E());
			commonHists.piPlusDEnergyHistD0bar->Fill(_pD_IN_D0CM_MEV.E());
		}

		// as a sanity check, compare the D0 four-momentum with the sum of the daughter four-momenta:
		if (printSanityChecks)
		{
			// mds OK
			TLorentzVector diff;
			diff = _pD0_IN_D0CM_MEV - _pA_IN_D0CM_MEV - _pB_IN_D0CM_MEV - _pC_IN_D0CM_MEV - _pD_IN_D0CM_MEV;
			std::cout << "pA 4-mom = " << _pA_IN_D0CM_MEV.Px() << ",    "
					  << _pA_IN_D0CM_MEV.Py() << ",    "
					  << _pA_IN_D0CM_MEV.Pz() << ",    "
					  << _pA_IN_D0CM_MEV.E() << ",    "
					  << _pA_IN_D0CM_MEV.M() << std::endl;
			std::cout << "pB 4-mom = " << _pB_IN_D0CM_MEV.Px() << ",    "
					  << _pB_IN_D0CM_MEV.Py() << ",    "
					  << _pB_IN_D0CM_MEV.Pz() << ",    "
					  << _pB_IN_D0CM_MEV.E() << ",    "
					  << _pB_IN_D0CM_MEV.M() << std::endl;
			std::cout << "pC 4-mom = " << _pC_IN_D0CM_MEV.Px() << ",    "
					  << _pC_IN_D0CM_MEV.Py() << ",    "
					  << _pC_IN_D0CM_MEV.Pz() << ",    "
					  << _pC_IN_D0CM_MEV.E() << ",    "
					  << _pC_IN_D0CM_MEV.M() << std::endl;
			std::cout << "pD 4-mom = " << _pD_IN_D0CM_MEV.Px() << ",    "
					  << _pD_IN_D0CM_MEV.Py() << ",    "
					  << _pD_IN_D0CM_MEV.Pz() << ",    "
					  << _pD_IN_D0CM_MEV.E() << ",    "
					  << _pD_IN_D0CM_MEV.M() << std::endl;
			std::cout << "diff.E()  =   " << diff.E() << std::endl;
			std::cout << "CM diff 4-mom =  " << diff.Px() << ",    "
					  << diff.Py() << ",    "
					  << diff.Pz() << ",    "
					  << diff.E() << std::endl;
		}

		//  note that _pA_IN_D0CM_MEV, _pB_IN_D0CM_MEV, etc., are in the D0 CM.
		//  we are going to define zhat as the pA_3vec+pB_3vec direction.
		//  to consider the helicity angles of the AB and CD pairs in their
		//  respective CMs, we should make Lorentz transformations along
		//  the zhat (or -zhat) directions. Note that the CD system is moving
		//  along the -zhat direction to start.
		TLorentzVector pAB_4vec = _pA_IN_D0CM_MEV + _pB_IN_D0CM_MEV;
		double energyAB = pAB_4vec.E();
		TVector3 betaAB;
		betaAB.SetXYZ(pAB_4vec.Px() / energyAB, pAB_4vec.Py() / energyAB, pAB_4vec.Pz() / energyAB);
		TLorentzVector pAprime_4vec = _pA_IN_D0CM_MEV;
		pAprime_4vec.Boost(-1. * betaAB);
		TLorentzVector pBprime_4vec = _pB_IN_D0CM_MEV;
		pBprime_4vec.Boost(-1. * betaAB);
		if (printSanityChecks)
		{
			std::cout << "After boost to AB frame: " << std::endl;
			std::cout << "pAprime_4vec: "; 
			pAprime_4vec.Print(); 
			std::cout << "pBprime_4vec: ";
			pBprime_4vec.Print();

			TLorentzVector testAB(pAB_4vec);
			testAB.Boost(-1. * betaAB);
			std::cout << "Boosted pAB_4vec: ";
			testAB.Print();
		}

		TLorentzVector pCD_4vec = _pC_IN_D0CM_MEV + _pD_IN_D0CM_MEV;
		double energyCD = pCD_4vec.E();
		TVector3 betaCD;
		betaCD.SetXYZ(pCD_4vec.Px() / energyCD, pCD_4vec.Py() / energyCD, pCD_4vec.Pz() / energyCD);
		TLorentzVector pCprime_4vec = _pC_IN_D0CM_MEV;
		pCprime_4vec.Boost(-1. * betaCD);
		TLorentzVector pDprime_4vec = _pD_IN_D0CM_MEV;
		pDprime_4vec.Boost(-1. * betaCD);
		if (printSanityChecks)
		{
			std::cout << "After boost to CD frame: " << std::endl;
			std::cout << "pCprime_4vec: "; 
			pCprime_4vec.Print(); 
			std::cout << "pDprime_4vec: ";
			pDprime_4vec.Print();

			TLorentzVector testCD(pCD_4vec);
			testCD.Boost(-1. * betaCD);
			std::cout << "Boosted pCD_4vec: ";
			testCD.Print();
		}

		TLorentzVector pABC_4vec = _pA_IN_D0CM_MEV + _pB_IN_D0CM_MEV + _pC_IN_D0CM_MEV;
		double mAB = pAB_4vec.M();			// m(K*bar) candidate
		double mABC = pABC_4vec.M();		// m(K*bar,pi-);
		double mABD = pABD_in_D0CM_MeV.M(); // m(K*bar,pi+);
		double mCD = pCD_4vec.M();			// m(pi-,pi+);

		commonHists.mAB->Fill(mAB);
		commonHists.mCD->Fill(mCD);

		if (abs(mAB - 892) < 50)
		{
			// these are K*,pi-,pi+ candidates
			//  next, make the K*,pi-,pi+ "Dalitz plot" for these candidates
			double s12 = mABC * mABC * 0.000001; // converted from MeV^2 to Gev^2
			double s13 = mABD * mABD * 0.000001; // converted from MeV^2 to Gev^2
			double s23 = mCD * mCD * 0.000001;	 // converted from MeV^2 to Gev^2
			commonHists.KstarPiPiDP1213->Fill(s12, s13);
			commonHists.KstarPiPiDP2313->Fill(s23, s13);
			commonHists.KstarPiPiDP2312->Fill(s23, s12);
		}

		TVector3 pAB_3vec = pAB_4vec.Vect();
		TVector3 pCD_3vec = pCD_4vec.Vect();
		TVector3 pA_3vec = _pA_IN_D0CM_MEV.Vect();
		TVector3 pB_3vec = _pB_IN_D0CM_MEV.Vect();
		TVector3 pC_3vec = _pC_IN_D0CM_MEV.Vect();
		TVector3 pD_3vec = _pD_IN_D0CM_MEV.Vect();

		TVector3 pAprime_3vec = pAprime_4vec.Vect();
		TVector3 pBprime_3vec = pBprime_4vec.Vect();
		TVector3 pCprime_3vec = pCprime_4vec.Vect();
		TVector3 pDprime_3vec = pDprime_4vec.Vect();

		TVector3 zhat = pAB_3vec.Unit();
		TVector3 yhat = (pA_3vec.Cross(pB_3vec)).Unit();
		TVector3 xhat = (yhat.Cross(zhat)).Unit();

		TVector3 yhatPrime = (pC_3vec.Cross(pD_3vec)).Unit();

		double cosPhi = (yhat.Dot(yhatPrime));
		double sinPhi = (xhat.Dot(yhatPrime));
		double phi = K3PiStudiesUtils::changeAngleRange_0_to_2pi(TMath::ATan2(sinPhi, cosPhi));
		double phiDiff = (verifyAngles) ? K3PiStudiesUtils::verifyAngle(yhat, yhatPrime, phi, false, "Event " + evtStr + " phi", printSanityChecks) : 0.0;

		double myPhiDiff = 0.0;
		if (verifyAngles)
		{
			double myPhi = K3PiStudiesUtils::changeAngleRange_0_to_2pi(K3PiStudiesUtils::angleBetweenDecayPlanesKutschke(pA_3vec, pB_3vec, pC_3vec, pD_3vec));
			myPhiDiff = myPhi - phi;
		}

		double tripleProduct = yhat.Dot(pC_3vec);

		// as a sanity check, compare phi with Adrian's Triple Product
		// using zhat rather than p_a \cross p_b for convvenience of visualization
		if (printSanityChecks)
		{
			std::cout << "pA_3vec  ";
			pA_3vec.Print();
			pAprime_4vec.Print();
			std::cout << "pB_3vec  ";
			pB_3vec.Print();
			pBprime_4vec.Print();
			std::cout << "pC_3vec  ";
			pC_3vec.Print();
			pCprime_4vec.Print();
			std::cout << "pD_3vec  ";
			pD_3vec.Print();
			pDprime_4vec.Print();
			std::cout << "pAB_3vec  ";
			pAB_3vec.Print();
			std::cout << "zhat   ";
			zhat.Print();
			std::cout << "yhat   ";
			yhat.Print();
			std::cout << "pCD_3vec  ";
			pCD_3vec.Print();
			std::cout << "yhatPrime  ";
			yhatPrime.Print();
		}

		double paX = pA_3vec.Dot(xhat);
		double pbX = pB_3vec.Dot(xhat);
		double pcX = pC_3vec.Dot(xhat);
		double pdX = pD_3vec.Dot(xhat);
		double paY = pA_3vec.Dot(yhat);
		double pbY = pB_3vec.Dot(yhat);
		double pcY = pC_3vec.Dot(yhat);
		double pdY = pD_3vec.Dot(yhat);
		double paZ = pA_3vec.Dot(zhat);
		double pbZ = pB_3vec.Dot(zhat);
		double pcZ = pC_3vec.Dot(zhat);
		double pdZ = pD_3vec.Dot(zhat);
		double paPrimeX = pAprime_3vec.Dot(xhat);
		double pbPrimeX = pBprime_3vec.Dot(xhat);
		double pcPrimeX = pCprime_3vec.Dot(xhat);
		double pdPrimeX = pDprime_3vec.Dot(xhat);
		double paPrimeY = pAprime_3vec.Dot(yhat);
		double pbPrimeY = pBprime_3vec.Dot(yhat);
		double pcPrimeY = pCprime_3vec.Dot(yhat);
		double pdPrimeY = pDprime_3vec.Dot(yhat);
		double paPrimeZ = pAprime_3vec.Dot(zhat);
		double pbPrimeZ = pBprime_3vec.Dot(zhat);
		double pcPrimeZ = pCprime_3vec.Dot(zhat);
		double pdPrimeZ = pDprime_3vec.Dot(zhat);

		double paPrimeMag = sqrt(paPrimeX * paPrimeX + paPrimeY * paPrimeY + paPrimeZ * paPrimeZ);
		double paPrimePT = sqrt(paPrimeX * paPrimeX + paPrimeY * paPrimeY);
		double cosThetaA = paPrimeZ / paPrimeMag;
		double sinThetaA = paPrimePT / paPrimeMag;
		double sin2ThetaA = 2.0 * sinThetaA * cosThetaA;

		double pcPrimeMag = sqrt(pcPrimeX * pcPrimeX + pcPrimeY * pcPrimeY + pcPrimeZ * pcPrimeZ);
		double pcPrimePT = sqrt(pcPrimeX * pcPrimeX + pcPrimeY * pcPrimeY);
		double cosThetaC = pcPrimeZ / pcPrimeMag;
		double sinThetaC = pcPrimePT / pcPrimeMag;
		double sin2ThetaC = 2.0 * sinThetaC * cosThetaC;

		if (printSanityChecks)
		{
			std::cout << "paX, paY, paZ =   " << paX << "   " << paY << "   " << paZ << std::endl;
			std::cout << "pbX, pbY, pbZ =   " << pbX << "   " << pbY << "   " << pbZ << std::endl;
			std::cout << "pcX, pcY, pcZ =   " << pcX << "   " << pcY << "   " << pcZ << std::endl;
			std::cout << "pdX, pdY, pdZ =   " << pdX << "   " << pdY << "   " << pdZ << std::endl;
			std::cout << "paPrimeX, paPrimeY, paPrimeZ =   " << paPrimeX << "   " << paPrimeY << "   " << paPrimeZ << std::endl;
			std::cout << "pbPrimeX, pbPrimeY, pbPrimeZ =   " << pbPrimeX << "   " << pbPrimeY << "   " << pbPrimeZ << std::endl;
			std::cout << "pcPrimeX, pcPrimeY, pcPrimeZ =   " << pcPrimeX << "   " << pcPrimeY << "   " << pcPrimeZ << std::endl;
			std::cout << "pdPrimeX, pdPrimeY, pdPrimeZ =   " << pdPrimeX << "   " << pdPrimeY << "   " << pdPrimeZ << std::endl;
			std::cout << "cosThetaA =  " << cosThetaA << "   and cosThetaC =  " << cosThetaC << std::endl;
		}

		commonHists.sanityPlot->Fill(tripleProduct, phi);

		if (abs(mAB - 892) < 35 && abs(mCD - 775 < 100))
		{ //// this looks at K*,rho region
			commonHists.mABmADForKstarRho->Fill(mAB, pAD_in_D0CM_MeV.M());
		}

		if (abs(mAB - 892) < 35 && mCD < 550)
		{ /////  this looks at "K*,f0" region
			commonHists.mABmADForKstarF0->Fill(mAB, pAD_in_D0CM_MeV.M());
		}

		if (mAB < 775 && abs(mCD - 775 < 75))
		{ /////  this looks at "kappa,rho" region
			commonHists.mABmADForKappaRho->Fill(mAB, pAD_in_D0CM_MeV.M());
		}

		//  now, repeat using the high-mass K,pi pair to define the reference plane
		commonHists.mADmCB->Fill(pAD_in_D0CM_MeV.M(), pCB_in_D0CM_MeV.M());
		commonHists.mKPimPiPi->Fill(pAD_in_D0CM_MeV.M(), pCB_in_D0CM_MeV.M());
		commonHists.mABmAD->Fill(mAB, pAD_in_D0CM_MeV.M());
		commonHists.mABmADzoomed->Fill(mAB, pAD_in_D0CM_MeV.M());

		if (mAB < 850 && pAD_in_D0CM_MeV.M() < 850)
		{
			TLorentzVector pABDlocal = _pA_IN_D0CM_MEV + _pB_IN_D0CM_MEV + _pD_IN_D0CM_MEV;
			commonHists.mABD_corner->Fill(pABDlocal.M());
			commonHists.cornerKPiPiMassSqHist->Fill(pABDlocal.M() * pABDlocal.M() / 1000000.); //  divide by 1000000 to get GeV**2

			TLorentzVector pBD = _pB_IN_D0CM_MEV + _pD_IN_D0CM_MEV; // pi+,pi+
			commonHists.mPiPiForLowKPiPi->Fill(pBD.M());
			commonHists.mABmCDForLowKPiPi->Fill(pAB_4vec.M(), pCD_4vec.M());
			commonHists.cornerKMinusEnergyHist->Fill(_pA_IN_D0CM_MEV.E());
			commonHists.cornerPiMinusEnergyHist->Fill(_pC_IN_D0CM_MEV.E());
			commonHists.cornerPiPlusEnergyHist->Fill(_pB_IN_D0CM_MEV.E());
			commonHists.cornerPiPlusEnergyHist->Fill(_pD_IN_D0CM_MEV.E());
			TLorentzVector pAC = _pA_IN_D0CM_MEV + _pC_IN_D0CM_MEV; // K-,pi-
			TLorentzVector pAB = _pA_IN_D0CM_MEV + _pB_IN_D0CM_MEV; // K-,pi+
			TLorentzVector pAD = _pA_IN_D0CM_MEV + _pD_IN_D0CM_MEV; // K-,pi+
			TLorentzVector pCB = _pC_IN_D0CM_MEV + _pB_IN_D0CM_MEV; // pi-,pi+
			TLorentzVector pCD = _pC_IN_D0CM_MEV + _pD_IN_D0CM_MEV; // pi-,pi+
			commonHists.cornerKMinusPiMinusMassHist->Fill(pAC.M());
			commonHists.cornerKMinusPiPlusMassHist->Fill(mAB);
			commonHists.cornerKMinusPiPlusMassHist->Fill(pAD.M());
			commonHists.cornerPiMinusPiPlusMassHist->Fill(pCB.M());
			commonHists.cornerPiMinusPiPlusMassHist->Fill(mCD);
			commonHists.cornerPiPlusPiPlusMassHist->Fill(pBD.M());

			TVector3 localZhat = pC_3vec.Unit();
			double pAz = localZhat.Dot(pA_3vec);
			double pBz = localZhat.Dot(pB_3vec);
			double pCz = localZhat.Dot(pC_3vec);
			double pDz = localZhat.Dot(pD_3vec);

			commonHists.cornerKMinusPzHist->Fill(pAz);
			commonHists.cornerPiPlusPzHist->Fill(pBz);
			commonHists.cornerPiMinusPzHist->Fill(pCz);
			commonHists.cornerPiPlusPzHist->Fill(pDz);

			double energyABD = pABD_in_D0CM_MeV.E();
			TVector3 betaABD;
			betaABD.SetXYZ(pABD_in_D0CM_MeV.Px() / energyABD, pABD_in_D0CM_MeV.Py() / energyABD, pABD_in_D0CM_MeV.Pz() / energyABD);
			TLorentzVector pAlocal_4vec = _pA_IN_D0CM_MEV;
			pAlocal_4vec.Boost(-1. * betaABD);
			TLorentzVector pBlocal_4vec = _pB_IN_D0CM_MEV;
			pBlocal_4vec.Boost(-1. * betaABD);
			TLorentzVector pDlocal_4vec = _pD_IN_D0CM_MEV;
			pDlocal_4vec.Boost(-1. * betaABD);
			TVector3 pAlocal_3vec = pAlocal_4vec.Vect();
			TVector3 pBlocal_3vec = pBlocal_4vec.Vect();
			TVector3 pDlocal_3vec = pDlocal_4vec.Vect();
			double cosThetaK = localZhat.Dot(pAlocal_3vec.Unit());
			commonHists.cornerKminusHelictyCosineHist->Fill(cosThetaK);
		}

		TVector3 pAD_3vec = pAD_in_D0CM_MeV.Vect();
		TVector3 pCB_3vec = pCB_in_D0CM_MeV.Vect();

		TVector3 zhatA = pAD_3vec.Unit();
		TVector3 yhatA = (pA_3vec.Cross(pD_3vec)).Unit();
		TVector3 xhatA = (yhatA.Cross(zhatA)).Unit();

		TVector3 yhatAPrime = (pC_3vec.Cross(pB_3vec)).Unit();

		double cosPhiA = (yhatA.Dot(yhatAPrime));
		double sinPhiA = (xhatA.Dot(yhatAPrime));
		double phiA = K3PiStudiesUtils::changeAngleRange_0_to_2pi(TMath::ATan2(sinPhiA, cosPhiA));
		double phiDiffA = (verifyAngles) ? K3PiStudiesUtils::verifyAngle(yhatA, yhatAPrime, phiA, false, "Event " + evtStr + " phiA", printSanityChecks) : 0.0;

		double myPhiADiff = 0.0;
		if (verifyAngles)
		{
			double myPhiA = K3PiStudiesUtils::changeAngleRange_0_to_2pi(K3PiStudiesUtils::angleBetweenDecayPlanesKutschke(pA_3vec, pD_3vec, pC_3vec, pB_3vec));
			myPhiADiff = myPhiA - phiA;
		}

		commonHists.cosVsinPlotA->Fill(cosPhiA, sinPhiA);

		if (printSanityChecks)
		{
			std::cout << "cosPhiA: " << cosPhiA << std::endl;
			std::cout << "sinPhiA: " << sinPhiA << std::endl;
		}
		commonHists.allPhiAHist->Fill(phiA);

		// Sept 14 additions
		commonHists.KmPipPipAllHist->Fill(mABD);
		bool KstarRhoCand = abs(mAB - 892) < 35 && abs(mCD - 775 < 100);
		if (!KstarRhoCand)
		{
			commonHists.KmPipPipNotKstarRhoCand->Fill(mABD);
		}

		unsigned int quadrant = K3PiStudiesUtils::determineQuadrant(sin2ThetaA, sin2ThetaC);

		commonHists.mABmCD->Fill(mAB, mCD);
		commonHists.mKPimPiPi->Fill(mAB, mCD);

		if (abs(mAB - 892) < 50)
		{
			// these are K*,pi-,pi+ candidates
			//  first, look at the pi-,pi+ inv mass for these candidates
			commonHists.mCDforKstar->Fill(mCD);
		}
		if (mAB < 800)
		{
			commonHists.mCDforLowKPiMass->Fill(mCD);
		}
		if (abs(mCD - 775) < 150)
		{
			commonHists.mABforRhoZero->Fill(mAB);
		}

		commonHists.cosVsinPlot->Fill(TMath::Cos(phi), TMath::Sin(phi));

		commonHists.cosThetaAHist->Fill(cosThetaA);
		commonHists.cosThetaCHist->Fill(cosThetaC);
		commonHists.cosThetaAcosThetaCHist->Fill(cosThetaA, cosThetaC);

		commonHists.allPhiHist->Fill(phi);
		if (_IS_D0)
		{
			commonHists.allPhiHistD0->Fill(phi);
		}
		else
		{
			commonHists.allPhiHistD0bar->Fill(phi);
		}

		// for testing
		double sinPhiTest = sin(phi);
		if (sinPhiTest >= 0.0)
		{
			commonHists.testPosSinPhi->Fill(sinPhiTest);
		}
		else
		{
			commonHists.testNegSinPhi->Fill(sinPhiTest);
		}
		double sin2PhiTest = sin(2.0 * phi);
		if (sin2PhiTest >= 0.0)
		{
			commonHists.testPosSin2Phi->Fill(sin2PhiTest);
		}
		else
		{
			commonHists.testNegSin2Phi->Fill(sin2PhiTest);
		}

		// look at phi for events in the K*,rho region, separating into D0 and D0bar samples
		if (abs(mAB - 892) < 35 && abs(mCD - 775 < 100))
		{ //// this looks at K*,rho region
			if (_IS_D0)
			{
				commonHists.allPhiHistD02KstarRho->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD02KstarRho->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD02KstarRho->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD02KstarRho->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD02KstarRho->Fill(phi);
				}
				commonHists.tAtCD02KstarRho->Fill(cosThetaA, cosThetaC);
			}
			else
			{
				commonHists.allPhiHistD0bar2KstarRho->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD0bar2KstarRho->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD0bar2KstarRho->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD0bar2KstarRho->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD0bar2KstarRho->Fill(phi);
				}
				commonHists.tAtCD0bar2KstarRho->Fill(cosThetaA, cosThetaC);
			}
		}

		// look at phi for events in the K*,f0 region, separating into D0 and D0bar samples
		if (abs(mAB - 892) < 35 && mCD < 550)
		{ /////  this looks at "K*,f0" region
			if (_IS_D0)
			{
				commonHists.allPhiHistD02KstarF0->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD02KstarF0->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD02KstarF0->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD02KstarF0->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD02KstarF0->Fill(phi);
				}
				commonHists.tAtCD02KstarF0->Fill(cosThetaA, cosThetaC);
			}
			else
			{
				commonHists.allPhiHistD0bar2KstarF0->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD0bar2KstarF0->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD0bar2KstarF0->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD0bar2KstarF0->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD0bar2KstarF0->Fill(phi);
				}
				commonHists.tAtCD0bar2KstarF0->Fill(cosThetaA, cosThetaC);
			}
		}

		// look at phi for events in the Kappa,rho region, separating into D0 and D0bar samples
		if (mAB < 775 && abs(mCD - 775 < 75))
		{ /////  this looks at "kappa,rho" region
			if (_IS_D0)
			{
				commonHists.allPhiHistD02KappaRho->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD02KappaRho->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD02KappaRho->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD02KappaRho->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD02KappaRho->Fill(phi);
				}
				commonHists.tAtCD02KappaRho->Fill(cosThetaA, cosThetaC);
			}
			else
			{
				commonHists.allPhiHistD0bar2KappaRho->Fill(phi);
				if (quadrant == 1)
				{
					commonHists.quad1PhiHistD0bar2KappaRho->Fill(phi);
				}
				else if (quadrant == 2)
				{
					commonHists.quad2PhiHistD0bar2KappaRho->Fill(phi);
				}
				else if (quadrant == 3)
				{
					commonHists.quad3PhiHistD0bar2KappaRho->Fill(phi);
				}
				else if (quadrant == 4)
				{
					commonHists.quad4PhiHistD0bar2KappaRho->Fill(phi);
				}
				commonHists.tAtCD0bar2KappaRho->Fill(cosThetaA, cosThetaC);
			}
		}

		return Phsp4Body(mAB, mCD, cosThetaA, cosThetaC, phi, phiDiff,
						 pAD_in_D0CM_MeV.M(), pCB_in_D0CM_MeV.M(), phiA, phiDiffA, myPhiDiff, myPhiADiff);
	}

	void createAsymHist(TH1 *d0Hist,
						TH1 *d0barHist,
						unsigned int quadrant,
						const std::string &resName,
						const TString &saveName,
						const TString &saveExt,
						bool printStatus)
	{
		//  do asymmetry calculations before re-scaling the distributions
		const unsigned int nD0 = d0Hist->GetEntries();
		const unsigned int nD0bar = d0barHist->GetEntries();
		if (nD0 == 0 || nD0bar == 0)
		{
			std::cout << "WARNING: For " << resName << "(quadrant " << quadrant << "), nD0 or nD0Bar is 0. Cannot make comparison histogram!" << std::endl;
			return;
		}

		std::function<double(double)> sinFunc = [](double phi) -> double
		{ return sin(phi); }; // have to do this or get unresolved overloaded function type error
		std::function<double(double)> sin2PhiLambda = [](double phi) -> double
		{ return sin(2.0 * phi); };

		const double scale = nD0 / nD0bar;

		const double nD0Above = K3PiStudiesUtils::countFuncResult(d0Hist, sinFunc, true);
		const double nD0Below = K3PiStudiesUtils::countFuncResult(d0Hist, sinFunc, false);
		const std::pair<double, double> D0AB = K3PiStudiesUtils::calcAsymmetry(nD0Above, nD0Below);
		const double D0AB_asymmetry = D0AB.first;
		const double D0AB_asymmetryErr = D0AB.second;

		const double nD0barAbove = K3PiStudiesUtils::countFuncResult(d0barHist, sinFunc, true);
		const double nD0barBelow = K3PiStudiesUtils::countFuncResult(d0barHist, sinFunc, false);
		const std::pair<double, double> D0barAB = K3PiStudiesUtils::calcAsymmetry(nD0barAbove, nD0barBelow);
		const double D0barAB_asymmetry = D0barAB.first;
		const double D0barAB_asymmetryErr = D0barAB.second;

		const std::pair<double, double> CP = K3PiStudiesUtils::invVarWeightedAvg(
			{D0AB_asymmetry, D0barAB_asymmetry},
			{D0AB_asymmetryErr, D0barAB_asymmetryErr});
		const double CPAsymmetry = CP.first;
		const double CPAsymmetryErr = CP.second;

		const std::pair<double, double> diffABCalc = K3PiStudiesUtils::invVarWeightedAvg(
			{D0AB_asymmetry, -1.0 * D0barAB_asymmetry},
			{D0AB_asymmetryErr, D0barAB_asymmetryErr});
		const double DiffAB = diffABCalc.first;
		const double DiffABErr = diffABCalc.second;
		if (CPAsymmetryErr != DiffABErr)
		{
			std::cout << "Error calculating asymmetries for " << resName << ", quadrant (" << quadrant << ")!" << std::endl;
			std::cout << "CP asym error: " << CPAsymmetryErr << std::endl;
			std::cout << "DiffAB error: " << DiffABErr << std::endl;
		}

		if (printStatus)
		{
			std::cout << "For " << resName << ", quadrant (" << quadrant << "):" << std::endl;
			std::cout << "nD0 = " << nD0 << std::endl;
			std::cout << "nD0Above =   " << nD0Above << std::endl;
			std::cout << "nD0Below =   " << nD0Below << std::endl;
			std::cout << "D0AB_asymmetry =   " << D0AB_asymmetry << "  +-  " << D0AB_asymmetryErr << std::endl;

			std::cout << "nD0Bar = " << nD0bar << std::endl;
			std::cout << "nD0BarAbove =   " << nD0barAbove << std::endl;
			std::cout << "nD0BarBelow =   " << nD0barBelow << std::endl;
			std::cout << "D0barAB_asymmetry =   " << D0barAB_asymmetry << "  +-  " << D0barAB_asymmetryErr << std::endl;
			std::cout << "CP Asymmetry =   " << CPAsymmetry << "  +-  " << CPAsymmetryErr << std::endl;
			std::cout << "DiffAB =   " << DiffAB << "  +-  " << DiffABErr << std::endl;
		}

		const double nD0Sin2PhiPlus = K3PiStudiesUtils::countFuncResult(d0Hist, sin2PhiLambda, true);
		const double nD0Sin2PhiMinus = K3PiStudiesUtils::countFuncResult(d0Hist, sin2PhiLambda, false);
		const std::pair<double, double> D0Sin2Phi = K3PiStudiesUtils::calcAsymmetry(nD0Sin2PhiPlus, nD0Sin2PhiMinus);
		const double D0Sin2Phi_asymmetry = D0Sin2Phi.first;
		const double D0Sin2Phi_asymmetryErr = D0Sin2Phi.second;

		const double nD0barSin2PhiPlus = K3PiStudiesUtils::countFuncResult(d0barHist, sin2PhiLambda, true);
		const double nD0barSin2PhiMinus = K3PiStudiesUtils::countFuncResult(d0barHist, sin2PhiLambda, false);
		const std::pair<double, double> D0barSin2Phi = K3PiStudiesUtils::calcAsymmetry(nD0barSin2PhiPlus, nD0barSin2PhiMinus);
		const double D0barSin2Phi_asymmetry = D0barSin2Phi.first;
		const double D0barSin2Phi_asymmetryErr = D0barSin2Phi.second;

		const std::pair<double, double> CPSin2Phi = K3PiStudiesUtils::invVarWeightedAvg(
			{D0Sin2Phi_asymmetry, D0barSin2Phi_asymmetry},
			{D0Sin2Phi_asymmetryErr, D0barSin2Phi_asymmetryErr});
		const double Sin2PhiCP_asymmetry = CPSin2Phi.first;
		const double Sin2PhiCP_asymmetryErr = CPSin2Phi.second;

		const std::pair<double, double> diffSin2PhiCalc = K3PiStudiesUtils::invVarWeightedAvg(
			{D0Sin2Phi_asymmetry, -1.0 * D0barSin2Phi_asymmetry},
			{D0Sin2Phi_asymmetryErr, D0barSin2Phi_asymmetryErr});
		const double DiffSin2Phi = diffSin2PhiCalc.first;
		const double DiffSin2PhiErr = diffSin2PhiCalc.second;
		if (Sin2PhiCP_asymmetryErr != DiffSin2PhiErr)
		{
			std::cout << "Error calculating sin 2 phi asymmetries for " << resName << ", quadrant (" << quadrant << ")!" << std::endl;
			std::cout << "Sin2PhiCP_asymmetry Error: " << Sin2PhiCP_asymmetryErr << std::endl;
			std::cout << "DiffSin2Phi error: " << DiffSin2PhiErr << std::endl;
		}

		if (printStatus)
		{
			std::cout << "nD0Sin2PhiPlus =   " << nD0Sin2PhiPlus << std::endl;
			std::cout << "nD0Sin2PhiMinus =   " << nD0Sin2PhiMinus << std::endl;
			std::cout << "D0Sin2Phi_asymmetry =   " << D0Sin2Phi_asymmetry << "  +-  " << D0Sin2Phi_asymmetryErr << std::endl;

			std::cout << "nD0barSin2PhiPlus =   " << nD0barSin2PhiPlus << std::endl;
			std::cout << "nD0barSin2PhiMinus =   " << nD0barSin2PhiMinus << std::endl;
			std::cout << "D0barSin2Phi_asymmetry =   " << D0barSin2Phi_asymmetry << "  +-  " << D0barSin2Phi_asymmetryErr << std::endl;

			std::cout << "Sin2PhiCP_asymmetry =   " << Sin2PhiCP_asymmetry << "  +-  " << Sin2PhiCP_asymmetryErr << std::endl;
			std::cout << "DiffSin2Phi =   " << DiffSin2Phi << "  +-  " << DiffSin2PhiErr << std::endl;
		}

		const double maximum = d0barHist->GetMaximum();
		if (printStatus)
		{
			std::cout << "max from " << d0barHist->GetName() << " = " << maximum << std::endl;
		}

		gStyle->SetOptStat(0);

		TCanvas c1;

		TString yLabel = K3PiStudiesUtils::makeYAxisLabel(
			CommonHistsWithKinematics::_NUM_PHI_BINS, 
			0.0, 
			K3PiStudiesUtils::_TWO_PI, 
			"rad", 
			false);
		TString normYLabel = K3PiStudiesUtils::makeYAxisLabel(
			CommonHistsWithKinematics::_NUM_PHI_BINS, 
			0.0, 
			K3PiStudiesUtils::_TWO_PI, 
			"rad", 
			true);

		// set style
		d0Hist->SetLineColor(kBlue);
		d0Hist->SetLineWidth(2);
		d0barHist->SetLineColor(kRed + 1);
		d0barHist->SetLineWidth(2);
		d0Hist->GetXaxis()->SetTitleSize(0.06);
		d0Hist->GetXaxis()->SetTitleOffset(0.75);
		d0Hist->GetXaxis()->SetLabelFont(62);
		d0Hist->GetXaxis()->CenterTitle(true);
		d0Hist->SetTitle(resName + " - Quad " + quadrant);
		d0Hist->SetXTitle("#phi [radians]");
		d0Hist->GetYaxis()->SetTitleSize(0.06);
		d0Hist->GetYaxis()->SetTitleOffset(0.75);

		// create legend
		TLegend leg(0.12, 0.76, 0.32, 0.89);
		K3PiStudiesUtils::makeTLegendBkgTransparent(leg);
		leg.AddEntry(d0Hist, "D^{0}", "L");
		leg.AddEntry(d0barHist, "#bar{D}^{0}", "L");

		// create text box
		TString nd0Str = std::to_string(nD0);
		TString nd0barStr = std::to_string(nD0bar);
		TString d0AsymStr;
		TString d0AsymErrStr;
		TString d0barAsymStr;
		TString d0barAsymErrStr;
		TString cpAsymStr;
		TString cpAsymErrStr;
		TString DiffABStr;
		TString d0Sin2PhiAsymStr;
		TString d0Sin2PhiAsymErrStr;
		TString d0barSin2PhiAsymStr;
		TString d0barSin2PhiAsymErrStr;
		TString cpSin2PhiAsymStr;
		TString cpSin2PhiAsymErrStr;
		TString DiffSin2PhiStr;
		d0AsymStr.Form("%4.1f\n", 100. * D0AB_asymmetry);
		d0AsymErrStr.Form("%4.1f\n", 100. * D0AB_asymmetryErr);
		d0barAsymStr.Form("%4.1f\n", 100. * D0barAB_asymmetry);
		d0barAsymErrStr.Form("%4.1f\n", 100. * D0barAB_asymmetryErr);
		cpAsymStr.Form("%4.1f\n", 100. * CPAsymmetry);
		cpAsymErrStr.Form("%4.1f\n", 100. * CPAsymmetryErr);
		DiffABStr.Form("%4.1f\n", 100. * DiffAB);
		d0Sin2PhiAsymStr.Form("%4.1f\n", 100. * D0Sin2Phi_asymmetry);
		d0Sin2PhiAsymErrStr.Form("%4.1f\n", 100. * D0Sin2Phi_asymmetryErr);
		d0barSin2PhiAsymStr.Form("%4.1f\n", 100. * D0barSin2Phi_asymmetry);
		d0barSin2PhiAsymErrStr.Form("%4.1f\n", 100. * D0barSin2Phi_asymmetryErr);
		cpSin2PhiAsymStr.Form("%4.1f\n", 100. * Sin2PhiCP_asymmetry);
		cpSin2PhiAsymErrStr.Form("%4.1f\n", 100. * Sin2PhiCP_asymmetryErr);
		DiffSin2PhiStr.Form("%4.1f\n", 100. * DiffSin2Phi);
		TPaveText pt1(0.50, 0.7, 0.88, 0.94, "NDC"); // NDC sets coords
		K3PiStudiesUtils::makeTPaveTextBkgTransparent(pt1);
		pt1.AddText("Asymmetries");
		pt1.AddText("sin(#phi)             sin(2#phi)");
		pt1.AddText("D^{0}:  ( " + d0AsymStr + " #pm " + d0AsymErrStr + ")%   (" + d0Sin2PhiAsymStr + " #pm " + d0Sin2PhiAsymErrStr + ")%");
		pt1.AddText("#bar{D}^{0}:  ( " + d0barAsymStr + " #pm " + d0barAsymErrStr + ")%   (" + d0barSin2PhiAsymStr + " #pm " + d0barSin2PhiAsymErrStr + ")%");
		pt1.AddText("CP:   ( " + cpAsymStr + " #pm " + cpAsymErrStr + ")%   (" + cpSin2PhiAsymStr + " #pm " + cpSin2PhiAsymErrStr + ")%");
		pt1.AddText("D^{0}-#bar{D}^{0}:  (" + DiffABStr + " #pm " + cpAsymErrStr + ")%   (" + DiffSin2PhiStr + " #pm " + cpSin2PhiAsymErrStr + ")%");
		pt1.AddText("n(D^{0}) = " + nd0Str + "           n(#bar{D}^{0}) = " + nd0barStr);

		// save unnormalized plots
		d0Hist->GetYaxis()->SetRangeUser(0., 1.25 * maximum);
		d0Hist->SetYTitle(yLabel);
		d0Hist->Draw("HIST");
		d0barHist->Draw("HIST SAME");
		leg.Draw("same");
		pt1.Draw("same");	
		c1.SaveAs(saveName + "_no_norm" + saveExt);

		// normalize and save plot
		d0Hist->Scale(1.00 / nD0);
		d0barHist->Scale(1.00 / nD0bar);
		d0Hist->GetYaxis()->SetRangeUser(0., 1.25 * maximum / nD0);
		d0Hist->SetYTitle(normYLabel);
		d0Hist->Draw("HIST");
		d0barHist->Draw("HIST SAME");
		leg.Draw("same");
		pt1.Draw("same");	
		c1.SaveAs(saveName + saveExt);
		
		std::cout << std::endl;
	}

	void K3PiStudies::processData(
		CommonHistsWithKinematics &commonHists,
		const TString &outputSubDir,
		const std::pair<double, double> &decayTimeLimits_ps,
		bool applyMikeCuts,
		const std::string &mode,
		bool usingCTau,
		const TString &histNamePrefix,
		bool printSanityChecks,
		const std::string &varType,
		bool comparePhsp,
		bool verifyAngles,
		const std::string &region)
	{
		if (fChain == 0)
			return;

		unsigned int numEvents = 0;
		unsigned int numEventsPassingCuts = 0;
		unsigned int numRS = 0;
		unsigned int numWS = 0;
		unsigned int numRSPass = 0;
		unsigned int numWSPass = 0;
		unsigned int totNumPhspDiffs = 0;

		double maxM12Diff = 0.0;
		double maxM34Diff = 0.0;
		double maxCos12Diff = 0.0;
		double maxCos34Diff = 0.0;
		double maxPhiDiff = 0.0;

		double maxPhiCompDiff = 0.0;
		double maxPhiACompDiff = 0.0;
		double maxPhiCompDiff2 = 0.0;
		double maxPhiACompDiff2 = 0.0;

		// create hists with cuts
		HistsToShowCuts cutHists(histNamePrefix);

		// begin loop over events
		Long64_t nentries = fChain->GetEntriesFast();
		Long64_t nbytes = 0, nb = 0;
		for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
			Long64_t ientry = LoadTree(jentry);
			if (ientry < 0)
				break;
			nb = fChain->GetEntry(jentry);
			nbytes += nb;
			// if (Cut(ientry) < 0) continue;

			// choose D0 vars we are using (ReFit)
			double myD0_mass = Dst_ReFit_D0_M_best;
			double myDeltaM = deltam_ReFit;
			double myD0_PT = Dst_ReFit_D0_PT;
			double myD0_P = Dst_ReFit_D0_P_best;
			double myD0_PX = Dst_ReFit_D0_PX;
			double myD0_PY = Dst_ReFit_D0_PY;
			double myD0_PZ = Dst_ReFit_D0_PZ;

			// choose the set of daughter vars we are using (D0Fit; ReFit; or D0_P0_*, D0_P1_*, D0_P2_*, D0_P3_*)
			double myK_PX = std::numeric_limits<double>::quiet_NaN();
			double myK_PY = std::numeric_limits<double>::quiet_NaN();
			double myK_PZ = std::numeric_limits<double>::quiet_NaN();
			double myK_PE = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_0_PX = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_0_PY = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_0_PZ = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_0_PE = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_1_PX = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_1_PY = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_1_PZ = std::numeric_limits<double>::quiet_NaN();
			double myPi_OS_1_PE = std::numeric_limits<double>::quiet_NaN();
			double myPi_SS_PX = std::numeric_limits<double>::quiet_NaN();
			double myPi_SS_PY = std::numeric_limits<double>::quiet_NaN();
			double myPi_SS_PZ = std::numeric_limits<double>::quiet_NaN();
			double myPi_SS_PE = std::numeric_limits<double>::quiet_NaN();
			if (boost::iequals(varType, K3PiStudiesUtils::_D0_FIT_FLAG))
			{
				myK_PX = id_verified_D0Fit_K_PX_best;
				myK_PY = id_verified_D0Fit_K_PY_best;
				myK_PZ = id_verified_D0Fit_K_PZ_best;
				myK_PE = id_verified_D0Fit_K_PE_best;

				myPi_OS_0_PX = id_verified_D0Fit_Pi_OS_0_PX_best;
				myPi_OS_0_PY = id_verified_D0Fit_Pi_OS_0_PY_best;
				myPi_OS_0_PZ = id_verified_D0Fit_Pi_OS_0_PZ_best;
				myPi_OS_0_PE = id_verified_D0Fit_Pi_OS_0_PE_best;

				myPi_OS_1_PX = id_verified_D0Fit_Pi_OS_1_PX_best;
				myPi_OS_1_PY = id_verified_D0Fit_Pi_OS_1_PY_best;
				myPi_OS_1_PZ = id_verified_D0Fit_Pi_OS_1_PZ_best;
				myPi_OS_1_PE = id_verified_D0Fit_Pi_OS_1_PE_best;

				myPi_SS_PX = id_verified_D0Fit_Pi_SS_PX_best;
				myPi_SS_PY = id_verified_D0Fit_Pi_SS_PY_best;
				myPi_SS_PZ = id_verified_D0Fit_Pi_SS_PZ_best;
				myPi_SS_PE = id_verified_D0Fit_Pi_SS_PE_best;
			}
			else if (boost::iequals(varType, K3PiStudiesUtils::_REFIT_FLAG))
			{
				myK_PX = id_verified_ReFit_D0_K_PX_best;
				myK_PY = id_verified_ReFit_D0_K_PY_best;
				myK_PZ = id_verified_ReFit_D0_K_PZ_best;
				myK_PE = id_verified_ReFit_D0_K_PE_best;

				myPi_OS_0_PX = id_verified_ReFit_D0_Pi_OS_0_PX_best;
				myPi_OS_0_PY = id_verified_ReFit_D0_Pi_OS_0_PY_best;
				myPi_OS_0_PZ = id_verified_ReFit_D0_Pi_OS_0_PZ_best;
				myPi_OS_0_PE = id_verified_ReFit_D0_Pi_OS_0_PE_best;

				myPi_OS_1_PX = id_verified_ReFit_D0_Pi_OS_1_PX_best;
				myPi_OS_1_PY = id_verified_ReFit_D0_Pi_OS_1_PY_best;
				myPi_OS_1_PZ = id_verified_ReFit_D0_Pi_OS_1_PZ_best;
				myPi_OS_1_PE = id_verified_ReFit_D0_Pi_OS_1_PE_best;

				myPi_SS_PX = id_verified_ReFit_D0_Pi_SS_PX_best;
				myPi_SS_PY = id_verified_ReFit_D0_Pi_SS_PY_best;
				myPi_SS_PZ = id_verified_ReFit_D0_Pi_SS_PZ_best;
				myPi_SS_PE = id_verified_ReFit_D0_Pi_SS_PE_best;
			}
			else if (boost::iequals(varType, K3PiStudiesUtils::_P_FLAG))
			{
				myK_PX = verified_id_D0_Part_K_PX;
				myK_PY = verified_id_D0_Part_K_PY;
				myK_PZ = verified_id_D0_Part_K_PZ;
				myK_PE = verified_id_D0_Part_K_PE;

				myPi_OS_0_PX = verified_id_D0_Part_OS_Pi_0_PX;
				myPi_OS_0_PY = verified_id_D0_Part_OS_Pi_0_PY;
				myPi_OS_0_PZ = verified_id_D0_Part_OS_Pi_0_PZ;
				myPi_OS_0_PE = verified_id_D0_Part_OS_Pi_0_PE;

				myPi_OS_1_PX = verified_id_D0_Part_OS_Pi_1_PX;
				myPi_OS_1_PY = verified_id_D0_Part_OS_Pi_1_PY;
				myPi_OS_1_PZ = verified_id_D0_Part_OS_Pi_1_PZ;
				myPi_OS_1_PE = verified_id_D0_Part_OS_Pi_1_PE;

				myPi_SS_PX = verified_id_D0_Part_SS_Pi_PX;
				myPi_SS_PY = verified_id_D0_Part_SS_Pi_PY;
				myPi_SS_PZ = verified_id_D0_Part_SS_Pi_PZ;
				myPi_SS_PE = verified_id_D0_Part_SS_Pi_PE;
			}
			else
			{
				std::cout << "Error getting type of daughter variables to use." << std::endl;
			}

			//  begin per event code
			numEvents++;

			// check for RS/WS
			bool _IS_D0 = K3PiStudiesUtils::isD0(Dst_pi_ID);
			int kaonInd = K3PiStudiesUtils::findKaon(D0_P0_ID, D0_P1_ID, D0_P2_ID, D0_P3_ID);
			bool isKaonNeg = K3PiStudiesUtils::isKaonNeg(kaonInd, D0_P0_ID, D0_P1_ID, D0_P2_ID, D0_P3_ID);
			bool isRS = K3PiStudiesUtils::isRS(_IS_D0, isKaonNeg);
			bool useRS = boost::iequals(mode, K3PiStudiesUtils::_RS_FLAG) || boost::iequals(mode, K3PiStudiesUtils::_BOTH_FLAG);
			bool useWS = boost::iequals(mode, K3PiStudiesUtils::_WS_FLAG) || boost::iequals(mode, K3PiStudiesUtils::_BOTH_FLAG);
			if (isRS)
			{
				numRS++;
				if (!useRS)
				{
					continue;
				}
			}
			else
			{
				numWS++;
				if (!useWS)
				{
					continue;
				}
			}

			// convert decay time to ps
			double decayTime_ns = (usingCTau) ? K3PiStudiesUtils::cTauMMToTauNS(D0_Loki_BPVLTIME) : D0_Loki_BPVLTIME;
			double decayTime_ps = K3PiStudiesUtils::tauNSToTauPS(decayTime_ns);

			// if processing in decay time bins, reject events outside bin edges
			if (!K3PiStudiesUtils::isWithinDecayTimeBin(decayTime_ps, decayTimeLimits_ps))
			{
				continue;
			}

			// check if it is in the m, delta m region we are interested in
			if (!K3PiStudiesUtils::isInD0MassRegion(region, myD0_mass))
			{
				continue;
			}
			if (!K3PiStudiesUtils::isInDeltaMRegion(region, myDeltaM))
			{
				continue;
			}

			bool passesDecayTimeCut = decayTime_ps > _D0_LIFETIME_CUT_PS;

			// Mike's cuts start here
			if (applyMikeCuts)
			{
				std::cout << "WARNING: APPLYING MIKE'S CUTS HAS NOT BEEN TESTED!!!" << std::endl;

				// begin cuts
				Double_t kProbCut = 0.20;

				cutHists.strippingLevelDeltaMHist->Fill(myDeltaM);
				cutHists.strippingLevelMassHist->Fill(myD0_mass);

				bool cutsA = false;
				if (abs(myDeltaM - 145.457) < 0.7)
				{
					cutsA = true;
				}

				if (verified_id_D0_Part_K_ProbNNk > kProbCut)
				{
					cutHists.histDeltaM->Fill(myDeltaM);
					if (cutsA)
					{
						cutHists.histDeltaM_selected->Fill(myDeltaM);
					}
				}

				if (cutsA)
				{
					cutHists.cutsAMassHist->Fill(myD0_mass);
					cutHists.KminusKprobHist->Fill(verified_id_D0_Part_K_ProbNNk);
					if (verified_id_D0_Part_K_ProbNNk < kProbCut)
					{
						cutHists.massHistAlowKprob->Fill(myD0_mass);
					}
					else
					{
						cutHists.massHistAhighKprob->Fill(myD0_mass);
					}
				}

				bool selectedMass = false;
				if (myD0_mass > 1850 && myD0_mass < 1882)
				{
					selectedMass = true;
				}

				bool cutsB = false;
				Double_t thetaX = 0;
				Double_t thetaY = 0;

				if (cutsA && (verified_id_D0_Part_K_ProbNNk > kProbCut) && myD0_PT > 5000 && D0_IPCHI2_OWNPV < 9 && Dst_pi_IPCHI2_OWNPV < 9 && passesDecayTimeCut && verified_id_D0_Part_OS_Pi_0_ProbNNmu < 0.50 && verified_id_D0_Part_OS_Pi_1_ProbNNmu < 0.5 && Dst_pi_ProbNNpi_common > 0.05 && Dst_pi_ProbNNmu_common < 0.50 && Dst_pi_ProbNNe_common < 0.50 && myD0_P > 40000 && myD0_PT < 16000)
				{
					if (_IS_D0)
					{
						cutHists.d0MassHist->Fill(myD0_mass);
						if (selectedMass)
						{
							cutHists.d0MassHistSelected->Fill(myD0_mass);
							cutHists.d0PhaseSpace->Fill(Dst_ReFit_D0_P_best, Dst_ReFit_D0_PT);
						}
					}
					else
					{
						cutHists.d0barMassHist->Fill(myD0_mass);
						if (selectedMass)
						{
							cutHists.d0barMassHistSelected->Fill(myD0_mass);
							cutHists.d0barPhaseSpace->Fill(myD0_P, myD0_PT);
						}
					}

					if (selectedMass)
					{
						cutsB = true;
					}
					cutHists.massHistB->Fill(myD0_mass); // FIXME should this be inside the above if?
					thetaX = atan(myD0_PX / myD0_PZ);
					thetaY = atan(myD0_PY / myD0_PZ);
					cutHists.thetaXY->Fill(thetaX, thetaY);
				}

				if (cutsA && verified_id_D0_Part_K_ProbNNk > kProbCut && abs(atan(myD0_PX / myD0_PZ)) > 0.02 &&
					abs(atan(myD0_PY / myD0_PZ)) > 0.02)
				{
					cutHists.testMassHist->Fill(myD0_mass);
				}

				if (cutsA && verified_id_D0_Part_K_ProbNNk > kProbCut && abs(thetaX) > 0.02 && abs(thetaY) > 0.02)
				{
					cutHists.cutsCMassHist->Fill(myD0_mass);
				}

				bool cutsC = false;
				if (cutsB && abs(atan(myD0_PX / myD0_PZ)) > 0.02 &&
					abs(atan(myD0_PY / myD0_PZ)) > 0.02)
				{
					cutsC = true;
				}

				//  At this point we have a good enough set of cuts to begin lookiing at the angles defined
				//  by triple products.
				if (!cutsB)
				{
					continue;
				}
			} // end if applying cuts
			else
			{
				if (passesDecayTimeCut == false)
				{
					continue;
				}
			}

			// end cuts
			numEventsPassingCuts++;
			if (isRS)
			{
				numRSPass++;
			}
			else
			{
				numWSPass++;
			}

			printSanityChecks = (printSanityChecks) ? numEventsPassingCuts == 1 : false; // only print sanity checks for first event we process

			// The first step is to create four-vectors for the D0 daughters.
			// find the index of the each daughter
			TLorentzVector k_vec;
			k_vec.SetPxPyPzE(myK_PX, myK_PY, myK_PZ, myK_PE);

			TLorentzVector pi_OS_0_4vec;
			pi_OS_0_4vec.SetPxPyPzE(myPi_OS_0_PX, myPi_OS_0_PY, myPi_OS_0_PZ, myPi_OS_0_PE);

			TLorentzVector pi_OS_1_4vec;
			pi_OS_1_4vec.SetPxPyPzE(myPi_OS_1_PX, myPi_OS_1_PY, myPi_OS_1_PZ, myPi_OS_1_PE);

			TLorentzVector pi_SS_4vec;
			pi_SS_4vec.SetPxPyPzE(myPi_SS_PX, myPi_SS_PY, myPi_SS_PZ, myPi_SS_PE);

			if (printSanityChecks)
			{
				std::cout << "      K: ";
				k_vec.Print("");
				std::cout << std::endl
						  << "OS Pi 1: ";
				pi_OS_0_4vec.Print("");
				std::cout << std::endl
						  << "OS Pi 2: ";
				pi_OS_1_4vec.Print("");
				std::cout << std::endl
						  << "  SS Pi: ";
				pi_SS_4vec.Print("");
				std::cout << std::endl;

				std::cout << "k_vec.M() (before boost): " << k_vec.M() << std::endl;
				std::cout << "pi_OS_0_4vec.M() (before boost): " << pi_OS_0_4vec.M() << std::endl;
				std::cout << "pi_OS_1_4vec.M() (before boost): " << pi_OS_1_4vec.M() << std::endl;
				std::cout << "pi_SS_4vec.M() (before boost): " << pi_SS_4vec.M() << std::endl;

				std::cout << "m(k + pi os 0): " << (k_vec + pi_OS_0_4vec).M() << std::endl;
				std::cout << "m(k + pi os 1): " << (k_vec + pi_OS_1_4vec).M() << std::endl;
				std::cout << "m(k + pi ss): " << (k_vec + pi_SS_4vec).M() << std::endl;
				std::cout << "m(pi ss + pi os 0): " << (pi_SS_4vec + pi_OS_0_4vec).M() << std::endl;
				std::cout << "m(pi ss + pi os 1): " << (pi_SS_4vec + pi_OS_1_4vec).M() << std::endl;
				std::cout << "m(pi os 0 + pi os 1): " << (pi_OS_0_4vec + pi_OS_1_4vec).M() << std::endl;
			}

			TLorentzVector D0_4vec = k_vec + pi_OS_0_4vec + pi_OS_1_4vec + pi_SS_4vec;
			Double_t energy = D0_4vec.E();
			TVector3 beta;
			beta.SetXYZ(D0_4vec.Px() / energy, D0_4vec.Py() / energy, D0_4vec.Pz() / energy);
			if (printSanityChecks)
			{
				std::cout << "D0 4-mom = " << D0_4vec.Px() << ",    "
						  << D0_4vec.Py() << ",    "
						  << D0_4vec.Pz() << ",    "
						  << D0_4vec.E() << std::endl;
				std::cout << "beta =   " << beta.X() << ",  " << beta.Y() << ",  " << beta.Z() << std::endl;
			}

			TLorentzVector _pD0_IN_D0CM_MEV = D0_4vec;
			_pD0_IN_D0CM_MEV.Boost(-1. * beta);
			if (printSanityChecks)
			{
				std::cout << "D0_CM 4-mom = " << _pD0_IN_D0CM_MEV.Px() << ",    "
						  << _pD0_IN_D0CM_MEV.Py() << ",    "
						  << _pD0_IN_D0CM_MEV.Pz() << ",    "
						  << _pD0_IN_D0CM_MEV.E() << std::endl;
			}

			//  create the D0 daughter four-vectors, first in the lab, and then boosted into the D0 CM
			TLorentzVector k_in_D0_CM_MeV = k_vec;
			TLorentzVector pi_OS_0_in_D0_CM_MeV = pi_OS_0_4vec;
			TLorentzVector pi_SS_in_D0_CM_MeV = pi_SS_4vec;
			TLorentzVector pi_OS_1_in_D0_CM_MeV = pi_OS_1_4vec;

			k_in_D0_CM_MeV.Boost(-1. * beta);
			pi_OS_0_in_D0_CM_MeV.Boost(-1. * beta);
			pi_SS_in_D0_CM_MeV.Boost(-1. * beta);
			pi_OS_1_in_D0_CM_MeV.Boost(-1. * beta);

			if (printSanityChecks)
			{
				std::cout << "k_vec.M() (after boost): " << k_vec.M() << std::endl;
				std::cout << "pi_OS_0_4vec.M() (after boost): " << pi_OS_0_4vec.M() << std::endl;
				std::cout << "pi_OS_1_4vec.M() (after boost): " << pi_OS_1_4vec.M() << std::endl;
				std::cout << "pi_SS_4vec.M() (after boost): " << pi_SS_4vec.M() << std::endl;
			}

			// mds      if (D0_TAU > 0.0010) {
			// mds        mKPimPiPiA->Fill(pAD_4vec.M(),pCB_4vec.M());
			// mds      }

			// fill common hists
			Phsp4Body myPhsp = addEntryToCommonHists(commonHists,
													 _IS_D0,
													 _pD0_IN_D0CM_MEV,
													 k_in_D0_CM_MeV,
													 pi_OS_0_in_D0_CM_MeV,
													 pi_OS_1_in_D0_CM_MeV,
													 pi_SS_in_D0_CM_MeV,
													 printSanityChecks,
													 jentry,
													 verifyAngles,
													 myD0_mass,
													 myDeltaM,
													 decayTime_ps);

			// compare the values from John's code to the ones we calculate here
			if (comparePhsp)
			{
				// ntuple making code has norm vector for pi pi plane rotated by 180 deg (ie, norm1 = p(OS pi) x p(SS pi) rather than norm2 = p(SS pi) x p(OS pi), as is done here)
				// and calcs sin phi using norm1 (pi pi plane) x norm2 (k pi plane) rather than k pi plane x pi pi plane, as is done here
				// i.e., in ntuple code:
				// n1 = - our yhatPrime
				// n2 = our yhat
				// So don't compare phi
				Phsp4Body ntuplePhsp = Phsp4Body(
					id_verified_D0Fit_m34_ord_best,
					id_verified_D0Fit_m12_ord_best,
					id_verified_D0Fit_cos34_ord_best,
					id_verified_D0Fit_cos12_ord_best,
					std::numeric_limits<double>::quiet_NaN(),
					0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

				int numDiffs = ntuplePhsp.compare5(myPhsp, K3PiStudiesUtils::combinedToleranceCompare, jentry, printSanityChecks);
				totNumPhspDiffs += numDiffs;

				double m12Diff = fabs(ntuplePhsp._m12_MeV - myPhsp._m12_MeV);
				if (m12Diff > maxM12Diff)
				{
					maxM12Diff = m12Diff;
				}
				double m34Diff = fabs(ntuplePhsp._m34_MeV - myPhsp._m34_MeV);
				if (m34Diff > maxM34Diff)
				{
					maxM34Diff = m34Diff;
				}
				double cos12Diff = fabs(ntuplePhsp._cos12 - myPhsp._cos12);
				if (cos12Diff > maxCos12Diff)
				{
					maxCos12Diff = cos12Diff;
				}
				double cos34Diff = fabs(ntuplePhsp._cos34 - myPhsp._cos34);
				if (cos34Diff > maxCos34Diff)
				{
					maxCos34Diff = cos12Diff;
				}
			}

			if (verifyAngles)
			{
				if (myPhsp._phi_diff > maxPhiCompDiff)
				{
					maxPhiCompDiff = myPhsp._phi_diff;
				}

				if (myPhsp._phiA_diff > maxPhiACompDiff)
				{
					maxPhiACompDiff = myPhsp._phiA_diff;
				}

				if (myPhsp._phi_diff2 > maxPhiCompDiff2)
				{
					maxPhiCompDiff2 = myPhsp._phi_diff2;
				}

				if (myPhsp._phiA_diff2 > maxPhiACompDiff2)
				{
					maxPhiACompDiff2 = myPhsp._phiA_diff2;
				}
			}
		} // end loop over events

		// save hists
		if (applyMikeCuts)
		{
			cutHists.saveHists(outputSubDir);
		}

		// print statistics
		printSummary(numEvents, numEventsPassingCuts, decayTimeLimits_ps);
		std::cout << numRS << " RS events were processed." << std::endl;
		std::cout << numRSPass << " RS events were selected." << std::endl;
		std::cout << numWS << " WS events were processed." << std::endl;
		std::cout << numWSPass << " WS events were selected." << std::endl
				  << std::endl;

		if (comparePhsp)
		{
			std::cout << "Found " << totNumPhspDiffs << " differences in ntuple phase space vars vs. phase space vars computed here." << std::endl;
			std::cout << "Max diff between m12 values: " << maxM12Diff << std::endl;
			std::cout << "Max diff between m34 values: " << maxM34Diff << std::endl;
			std::cout << "Max diff between cos12 values: " << maxCos12Diff << std::endl;
			std::cout << "Max diff between cos34 values: " << maxCos34Diff << std::endl;
			std::cout << "Didn't compare phi values." << std::endl
					  << std::endl;
		}

		if (verifyAngles)
		{
			std::cout << "Max diff between our computed phi and phi from .Angle(): " << maxPhiCompDiff << std::endl;
			std::cout << "Max diff between our computed phiA and phiA from .Angle(): " << maxPhiACompDiff << std::endl;
			std::cout << "Max diff between our computed phi and phi from Kutschke equation: " << maxPhiCompDiff2 << std::endl;
			std::cout << "Max diff between our computed phiA and phiA from Kutschke equation: " << maxPhiACompDiff2 << std::endl
					  << std::endl;
		}
	}

	void processToyMC(
		CommonHistsWithKinematics &commonHists,
		const std::vector<std::string> &inputFiles,
		const std::pair<double, double> &decayTimeLimits_ps,
		bool printSanityChecks,
		bool verifyAngles,
		const std::string &region)
	{
		std::cout << "WARNING: TOY MC PROCESSING CODE HAS NOT BEEN TESTED!!!" << std::endl;

		unsigned int numEvents = 0;
		unsigned int numEventsPassingCuts = 0;

		for (auto const &inputFile : inputFiles)
		{
			// build reader for root file
			TFile *f = TFile::Open(inputFile.c_str());
			TTreeReader reader("DecayTree", f);
			// TTreeReaderValue<double> readerM12(reader, "m12");
			// TTreeReaderValue<double> readerM34(reader, "m34");
			// TTreeReaderValue<double> readerC12(reader, "c12");
			// TTreeReaderValue<double> readerC34(reader, "c34");
			// TTreeReaderValue<double> readerPhi(reader, "phi");
			TTreeReaderValue<double> readerDT(reader, "dtime");
			//TTreeReaderValue<bool> readerisD0(reader, "is_D0");
			//TTreeReaderValue<double> readerd0MassGeV(reader, "d0_Mass_GeV");
			TTreeReaderValue<double> readerkMinus_PE_GeV(reader, "kMinus_PE_GeV");
			TTreeReaderValue<double> readerkMinus_Px_GeV(reader, "kMinus_Px_GeV");
			TTreeReaderValue<double> readerkMinus_Py_GeV(reader, "kMinus_Py_GeV");
			TTreeReaderValue<double> readerkMinus_Pz_GeV(reader, "kMinus_Pz_GeV");
			TTreeReaderValue<double> readerpiPlus1_PE_GeV(reader, "piPlus1_PE_GeV");
			TTreeReaderValue<double> readerpiPlus1_Px_GeV(reader, "piPlus1_Px_GeV");
			TTreeReaderValue<double> readerpiPlus1_Py_GeV(reader, "piPlus1_Py_GeV");
			TTreeReaderValue<double> readerpiPlus1_Pz_GeV(reader, "piPlus1_Pz_GeV");
			TTreeReaderValue<double> readerpiPlus2_PE_GeV(reader, "piPlus2_PE_GeV");
			TTreeReaderValue<double> readerpiPlus2_Px_GeV(reader, "piPlus2_Px_GeV");
			TTreeReaderValue<double> readerpiPlus2_Py_GeV(reader, "piPlus2_Py_GeV");
			TTreeReaderValue<double> readerpiPlus2_Pz_GeV(reader, "piPlus2_Pz_GeV");
			TTreeReaderValue<double> readerpiMinus_PE_GeV(reader, "piMinus_PE_GeV");
			TTreeReaderValue<double> readerpiMinus_Px_GeV(reader, "piMinus_Px_GeV");
			TTreeReaderValue<double> readerpiMinus_Py_GeV(reader, "piMinus_Py_GeV");
			TTreeReaderValue<double> readerpiMinus_Pz_GeV(reader, "piMinus_Pz_GeV");

			bool _IS_D0 = true;
			std::cout << "FIXME _IS_DO flag!" << std::endl;

			// read in events
			std::cout << "Reading in events from file " << inputFile << "..." << std::endl;
			while (reader.Next())
			{
				double dtime_ps = *readerDT;
				
				// if processing in decay time bins, reject events outside bin edges
				if (!K3PiStudiesUtils::isWithinDecayTimeBin(dtime_ps, decayTimeLimits_ps))
				{
					continue;
				}


				TLorentzVector kMinus_in_D0_CM_MeV;
				kMinus_in_D0_CM_MeV.SetE(*readerkMinus_PE_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				kMinus_in_D0_CM_MeV.SetPx(*readerkMinus_Px_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				kMinus_in_D0_CM_MeV.SetPy(*readerkMinus_Py_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				kMinus_in_D0_CM_MeV.SetPz(*readerkMinus_Pz_GeV * K3PiStudiesUtils::_GEV_TO_MEV);

				TLorentzVector piPlus1_in_D0_CM_MeV;
				piPlus1_in_D0_CM_MeV.SetE(*readerpiPlus1_PE_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus1_in_D0_CM_MeV.SetPx(*readerpiPlus1_Px_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus1_in_D0_CM_MeV.SetPy(*readerpiPlus1_Py_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus1_in_D0_CM_MeV.SetPz(*readerpiPlus1_Pz_GeV * K3PiStudiesUtils::_GEV_TO_MEV);

				TLorentzVector piPlus2_in_D0_CM_MeV;
				piPlus2_in_D0_CM_MeV.SetE(*readerpiPlus2_PE_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus2_in_D0_CM_MeV.SetPx(*readerpiPlus2_Px_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus2_in_D0_CM_MeV.SetPy(*readerpiPlus2_Py_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piPlus2_in_D0_CM_MeV.SetPz(*readerpiPlus2_Pz_GeV * K3PiStudiesUtils::_GEV_TO_MEV);

				TLorentzVector piMinus_in_D0_CM_MeV;
				piMinus_in_D0_CM_MeV.SetE(*readerpiMinus_PE_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piMinus_in_D0_CM_MeV.SetPx(*readerpiMinus_Px_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piMinus_in_D0_CM_MeV.SetPy(*readerpiMinus_Py_GeV * K3PiStudiesUtils::_GEV_TO_MEV);
				piMinus_in_D0_CM_MeV.SetPz(*readerpiMinus_Pz_GeV * K3PiStudiesUtils::_GEV_TO_MEV);

				TLorentzVector _pD0_IN_D0CM_MEV = kMinus_in_D0_CM_MeV + piPlus1_in_D0_CM_MeV + piPlus2_in_D0_CM_MeV + piMinus_in_D0_CM_MeV;
				double mD0_MeV = _pD0_IN_D0CM_MEV.M();

				numEvents++;

				// add cut on decay time to duplicate what is done for data
				if (dtime_ps <= K3PiStudies::_D0_LIFETIME_CUT_PS)
				{
					continue;
				}

				// apply cut on D0 mass to look at region selected. Can't do delta M cut - value not saved in toy MC ntuples
				if (!K3PiStudiesUtils::isInD0MassRegion(region, mD0_MeV))
				{
					continue;
				}

				numEventsPassingCuts++;

				// fill common hists
				printSanityChecks = (printSanityChecks) ? numEventsPassingCuts == 1 : false; // only print sanity checks for first event we process
				addEntryToCommonHists(commonHists,
									  _IS_D0,
									  _pD0_IN_D0CM_MEV,
									  kMinus_in_D0_CM_MeV,
									  piPlus1_in_D0_CM_MeV,
									  piPlus2_in_D0_CM_MeV,
									  piMinus_in_D0_CM_MeV,
									  printSanityChecks,
									  numEvents,
									  verifyAngles,
									  _pD0_IN_D0CM_MEV.M(),
									  0.0,
									  dtime_ps); // delta m isn't generated
			}									 // end while loop for event reader

			// DO NOT MANUALLY CLOSE ROOT FILE WITH F->CLOSE() - NOT DOCUMENTED BUT TTREEREADER'S DESTRUCTOR DOES IT ALREADY
		} // end loop over input files

		// print statistics
		std::cout << "Processed events from " << inputFiles.size() << " files." << std::endl;
		printSummary(numEvents, numEventsPassingCuts, decayTimeLimits_ps);
	}

} // end namespace K3PiStudies

int main(int argc, char *argv[])
{
	// get user input
	CLI::App app{"K3Pi Studies"};
	bool isToyMC = false;
	app.add_flag("--toyMC", isToyMC,
				 "Use this flag if the sample is toy MC.");
	std::string mode = "";
	app.add_option("-m", mode,
				   "The type of data to proccess: either RS, WS, or BOTH")
		->required()
		->check(CLI::IsMember({K3PiStudies::K3PiStudiesUtils::_RS_FLAG, K3PiStudies::K3PiStudiesUtils::_WS_FLAG, K3PiStudies::K3PiStudiesUtils::_BOTH_FLAG}, CLI::ignore_case));
	std::string region = "";
	app.add_option("-r", region,
				   "The (m, deltaM) region in which to process data (applies m, deltaM cut): either ALL or SIGNAL")
		->required()
		->check(CLI::IsMember({K3PiStudies::K3PiStudiesUtils::_ALL_REGION_FLAG, K3PiStudies::K3PiStudiesUtils::_SIG_REGION_FLAG}, CLI::ignore_case));
	std::string varType = "";
	app.add_option("-v", varType,
				   "The variable type to use for the daughter momenta: either REFIT, D0_FIT, or P (the D0_P0_PX, ... vars) [not used for toy MC]")
		->required()
		->check(CLI::IsMember({K3PiStudies::K3PiStudiesUtils::_REFIT_FLAG, K3PiStudies::K3PiStudiesUtils::_D0_FIT_FLAG, K3PiStudies::K3PiStudiesUtils::_P_FLAG}, CLI::ignore_case));
	std::string inputFilenames = "";
	app.add_option("-f", inputFilenames,
				   "Comma separated list of root files with data to process.")
		->required();
	std::string outDir = "";
	app.add_option("-o", outDir,
				   "Directory in which to save output files (do not include trailing /).")
		->required();
	bool processInDecayTimeBins = false;
	app.add_flag("--processInDecayTimeBins", processInDecayTimeBins,
				 "Use this flag if want to look at the sample in bins of decay time.");
	bool comparePhsp = false;
	app.add_flag("--comparePhsp", comparePhsp,
				 "Compare the values of the phase space variables in the ntuple to the ones we calculate here (only for D0_Fit vars)");
	bool applyMikeCuts = false;
	app.add_flag("--applyMikeCuts", applyMikeCuts,
				 "Set to true if want to apply Mike's original cuts to data.");
	bool usingCTau = false;
	app.add_flag("--usingCTau", usingCTau,
				 "Set to true if the D0 decay time is given as ctau (in mm) instead of tau (in ns).");
	bool useLHCbStyle = false;
	app.add_flag("--useLHCbStyle", useLHCbStyle,
				 "Set to true if want to use LHCb style for plots");
	bool printSanityChecks = false;
	app.add_flag("--printSanityChecks", printSanityChecks,
				 "Set to true if want to print info for the first event");
	bool verifyAngles = false;
	app.add_flag("--verifyAngles", verifyAngles,
				 "Set to true if want to check that our calculated angles between vectors match results of ROOT's .Angle method");
	CLI11_PARSE(app, argc, argv);
	std::vector<std::string> inRootFiles = K3PiStudies::K3PiStudiesUtils::buildListFromCommaSepStr(inputFilenames);

	std::string _SAVE_EXT = ".png";

	if (comparePhsp && !(boost::iequals(varType, K3PiStudies::K3PiStudiesUtils::_D0_FIT_FLAG)))
	{
		std::cout << "Can only compare the values of the phase space variables in the ntuple to the ones we calculate here when using the D0Fit variables for the daughter momenta." << std::endl;
		return -1;
	}

	std::cout << std::boolalpha;
	std::cout << std::endl
			  << "Processing data with the following options: " << std::endl;
	std::cout << "Is toy MC: " << isToyMC << std::endl;
	std::cout << "Mode: " << mode << std::endl;
	std::cout << "Region: " << region << std::endl;
	std::cout << "Daughter variable type: " << varType << std::endl;
	std::cout << "Files: " << inputFilenames << std::endl;
	std::cout << "Output directory: " << outDir << std::endl;
	std::cout << "Processing in decay time bins: " << processInDecayTimeBins << std::endl;
	std::cout << "Applying Mike's cuts: " << applyMikeCuts << std::endl;
	std::cout << "Using c*tau: " << usingCTau << std::endl;
	std::cout << "Using LHCb style: " << useLHCbStyle << std::endl;
	std::cout << "Comparing phase space calculations: " << comparePhsp << std::endl;
	std::cout << "Printing sanity checks: " << printSanityChecks << std::endl;
	std::cout << "Verifying angles: " << verifyAngles << std::endl
			  << std::endl;

	if (useLHCbStyle)
	{
		// LHCbStyle::lhcbStyle(true);
		std::cout << "LHCb style: TODO" << std::endl
				  << std::endl;
	}

	K3PiStudies::K3PiStudiesUtils::silenceROOTHistSaveMsgs();
	K3PiStudies::K3PiStudiesUtils::changeToRainbowPalette();

	std::vector<std::pair<double, double>> decayTimeLims_ps;
	if (processInDecayTimeBins)
	{
		std::vector<double> upperBinEdges = {
			K3PiStudies::K3PiStudiesUtils::_D0_LIFETIME_PS,
			2.0 * K3PiStudies::K3PiStudiesUtils::_D0_LIFETIME_PS,
			3.0 * K3PiStudies::K3PiStudiesUtils::_D0_LIFETIME_PS,
			4.0 * K3PiStudies::K3PiStudiesUtils::_D0_LIFETIME_PS,
			5.0 * K3PiStudies::K3PiStudiesUtils::_D0_LIFETIME_PS};

		// build vector with decay time bin edges
		decayTimeLims_ps = K3PiStudies::K3PiStudiesUtils::makeTimeBins(upperBinEdges);
	}
	else
	{
		// no processing in decay time bins; just one bin that spans all decay times
		decayTimeLims_ps.push_back(std::make_pair(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()));
	}

	std::pair<double, double> regAxisBoundsMD0MeV = K3PiStudies::K3PiStudiesUtils::getRegionAxisBoundsMD0MeV(region);
	std::pair<double, double> regAxisBoundsDeltaMMeV = K3PiStudies::K3PiStudiesUtils::getRegionAxisBoundsDeltaMMeV(region);

	// create output dir
	std::time_t now = std::time(0);
	boost::filesystem::path outputSubDir(outDir + "/angular_dist_results_" + now + "/");
	boost::filesystem::create_directory(outputSubDir);

	std::ofstream out;

	// write out list of files we are processing
	std::string listOfProcessedFiles = outputSubDir.string() + "list_of_processed_root_files.txt";
	out.open(listOfProcessedFiles, std::ios::trunc);
	for (auto const &f : inRootFiles)
	{
		out << f << std::endl;
	}
	out.close();

	// write out options we used to produce these plots
	std::string runOptionsList = outputSubDir.string() + "run_options.txt";
	out.open(runOptionsList, std::ios::trunc);
	{
		out << "Is toy MC: " << isToyMC << std::endl;
		out << "Mode: " << mode << std::endl;
		out << "Region: " << region << std::endl;
		out << "Daughter variable type: " << varType << std::endl;
		out << "Applying Mike's cuts: " << applyMikeCuts << std::endl;
		out << "Using c*tau: " << usingCTau << std::endl;

		out << "Plot axis bounds for this region: " << std::endl;
		out << regAxisBoundsMD0MeV.first << " <= m(D0) <= " << regAxisBoundsMD0MeV.second << " [MeV]" << std::endl;
		out << regAxisBoundsDeltaMMeV.first << " <= delta M <= " << regAxisBoundsDeltaMMeV.second << " [MeV]" << std::endl;

		out << "Region bounds (i.e., m(D0) and deltaM cut applied):" << std::endl;
		out << K3PiStudies::K3PiStudiesUtils::printRegionBoundsMD0(region) << std::endl;
		out << K3PiStudies::K3PiStudiesUtils::printRegionBoundsDeltaM(region) << std::endl;
	}
	out.close();

	// write out decay time bin edges if processing in decay time bins
	std::string decayTimeBinList = outputSubDir.string() + "decay_time_bins.txt";
	out.open(decayTimeBinList, std::ios::trunc);
	for (unsigned int d = 0; d < decayTimeLims_ps.size(); d++)
	{
		double lowerBinEdge_ps = decayTimeLims_ps[d].first;
		double upperBinEdge_ps = decayTimeLims_ps[d].second;
		out << "Bin " << std::to_string(d) << ": " << lowerBinEdge_ps << " ps <= decay time < " << upperBinEdge_ps << " ps" << std::endl;
	}
	out.close();

	for (unsigned int d = 0; d < decayTimeLims_ps.size(); d++)
	{
		// if processing in decay time bins, create a sub dir to hold results for each decay time bin
		if (processInDecayTimeBins)
		{
			outputSubDir = (outDir + "/angular_dist_results_" + now + "/decay_time_bin" + d + "/");
			boost::filesystem::create_directory(outputSubDir);

			std::cout << "Processing decay time bin " << d << "..." << std::endl;
		}

		//// create root save file
		// TString outRootFile = outputSubDir.string()+"myOutputFile.root";
		// TFile* myOutputFile = new TFile(outRootFile, "RECREATE");

		const TString histNamePrefix = (processInDecayTimeBins) ? "t bin " + std::to_string(d) : "";

		// create hists

		K3PiStudies::CommonHistsWithKinematics commonHists(
			histNamePrefix,
			regAxisBoundsMD0MeV.first,
			regAxisBoundsMD0MeV.second,
			regAxisBoundsDeltaMMeV.first,
			regAxisBoundsDeltaMMeV.second);

		if (isToyMC)
		{
			K3PiStudies::processToyMC(commonHists, inRootFiles, decayTimeLims_ps[d], printSanityChecks, verifyAngles, region);
		}
		else
		{
			TChain *chain = new TChain("DecayTree", "");
			for (auto const &f : inRootFiles)
			{
				chain->Add(f.c_str());
			}
			K3PiStudies::K3PiStudies data(chain);
			data.processData(
				commonHists,
				outputSubDir.string(),
				decayTimeLims_ps[d],
				applyMikeCuts,
				mode,
				usingCTau,
				histNamePrefix,
				printSanityChecks,
				varType,
				comparePhsp,
				verifyAngles,
				region);
		}

		if (printSanityChecks)
		{
			std::function<double(double)> sinFunc = [](double phi) -> double
			{ return sin(phi); }; // have to do this or get unresolved overloaded function type error
			std::function<double(double)> sin2PhiLambda = [](double phi) -> double
			{ return sin(2.0 * phi); };

			std::cout << "Num phi: " << int(commonHists.allPhiHist->GetEntries()) << std::endl;

			int numPosSinComputed = K3PiStudies::K3PiStudiesUtils::countFuncResult(commonHists.allPhiHist, sinFunc, true);
			int numNegSinComputed = K3PiStudies::K3PiStudiesUtils::countFuncResult(commonHists.allPhiHist, sinFunc, false);
			std::cout << "Num positive sin phi: " << int(commonHists.testPosSinPhi->GetEntries()) << std::endl;
			std::cout << "Num negative sin phi: " << int(commonHists.testNegSinPhi->GetEntries()) << std::endl;
			std::cout << "Num positive sin phi computed: " << numPosSinComputed << std::endl;
			std::cout << "Num negative sin phi computed: " << numNegSinComputed << std::endl;

			int numPosSin2Computed = K3PiStudies::K3PiStudiesUtils::countFuncResult(commonHists.allPhiHist, sin2PhiLambda, true);
			int numNegSin2Computed = K3PiStudies::K3PiStudiesUtils::countFuncResult(commonHists.allPhiHist, sin2PhiLambda, false);
			std::cout << "Num positive sin 2 phi: " << int(commonHists.testPosSin2Phi->GetEntries()) << std::endl;
			std::cout << "Num negative sin 2 phi: " << int(commonHists.testNegSin2Phi->GetEntries()) << std::endl;
			std::cout << "Num positive sin 2 phi computed: " << numPosSin2Computed << std::endl;
			std::cout << "Num negative sin 2 phi computed: " << numNegSin2Computed << std::endl;
		}

		gStyle->SetOptStat(0);
		//  ***  begin KstarRho calculations & plotting  ***
		//  do asymmetry calculations before re-scaling the distributions
		K3PiStudies::createAsymHist(commonHists.quad1PhiHistD02KstarRho,
									commonHists.quad1PhiHistD0bar2KstarRho,
									1,
									"(K*, #rho)",
									outputSubDir.string() + "compareQuad1PhiKstarRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad2PhiHistD02KstarRho,
									commonHists.quad2PhiHistD0bar2KstarRho,
									2,
									"(K*, #rho)",
									outputSubDir.string() + "compareQuad2PhiKstarRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad3PhiHistD02KstarRho,
									commonHists.quad3PhiHistD0bar2KstarRho,
									3,
									"(K*, #rho)",
									outputSubDir.string() + "compareQuad3PhiKstarRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad4PhiHistD02KstarRho,
									commonHists.quad4PhiHistD0bar2KstarRho,
									4,
									"(K*, #rho)",
									outputSubDir.string() + "compareQuad4PhiKstarRho",
									_SAVE_EXT, true);
		//  ***  end of KstarRho calculations & plotting  ***

		//  ***  begin KstarF0 calculations & plotting  ***
		//  do asymmetry calculations before re-scaling the distributions
		K3PiStudies::createAsymHist(commonHists.quad1PhiHistD02KstarF0,
									commonHists.quad1PhiHistD0bar2KstarF0,
									1,
									"(K*, f(0))",
									outputSubDir.string() + "compareQuad1PhiKstarF0",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad2PhiHistD02KstarF0,
									commonHists.quad2PhiHistD0bar2KstarF0,
									2,
									"(K*, f(0))",
									outputSubDir.string() + "compareQuad2PhiKstarF0",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad3PhiHistD02KstarF0,
									commonHists.quad3PhiHistD0bar2KstarF0,
									3,
									"(K*, f(0))",
									outputSubDir.string() + "compareQuad3PhiKstarF0",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad4PhiHistD02KstarF0,
									commonHists.quad4PhiHistD0bar2KstarF0,
									4,
									"(K*, f(0))",
									outputSubDir.string() + "compareQuad4PhiKstarF0",
									_SAVE_EXT, true);

		//  ***  begin Kappa,rho calculations & plotting  ***
		//  do asymmetry calculations before re-scaling the distributions
		K3PiStudies::createAsymHist(commonHists.quad1PhiHistD02KappaRho,
									commonHists.quad1PhiHistD0bar2KappaRho,
									1,
									"(#kappa, #rho)",
									outputSubDir.string() + "compareQuad1PhiKappaRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad2PhiHistD02KappaRho,
									commonHists.quad2PhiHistD0bar2KappaRho,
									2,
									"(#kappa, #rho)",
									outputSubDir.string() + "compareQuad2PhiKappaRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad3PhiHistD02KappaRho,
									commonHists.quad3PhiHistD0bar2KappaRho,
									3,
									"(#kappa, #rho)",
									outputSubDir.string() + "compareQuad3PhiKappaRho",
									_SAVE_EXT, true);
		K3PiStudies::createAsymHist(commonHists.quad4PhiHistD02KappaRho,
									commonHists.quad4PhiHistD0bar2KappaRho,
									4,
									"(#kappa, #rho)",
									outputSubDir.string() + "compareQuad4PhiKappaRho",
									_SAVE_EXT, true);
		//  ***  end of KappaRho calculations & plotting  ***

		// save hists
		commonHists.saveHists(outputSubDir.string());
		// myOutputFile->Write();
		// myOutputFile->Close();
	} // end loop over decay time bins

	std::cout << "Done." << std::endl;
}