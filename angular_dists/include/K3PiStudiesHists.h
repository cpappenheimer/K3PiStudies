// Declares histograms used by the K3PiStudies.cpp plotting code.

#pragma once

#include <string>

#include <TString.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "K3PiStudiesUtils.h"

namespace K3PiStudies
{

	class HistsToShowCuts final
	{
	private:
		const TString _name_prefix;

	public:
		HistsToShowCuts(const TString &namePrefix) : _name_prefix(namePrefix) {}
		HistsToShowCuts(const HistsToShowCuts &copyMe) = delete;
		HistsToShowCuts(HistsToShowCuts &&moveMe) = delete;
		HistsToShowCuts &operator=(const HistsToShowCuts &copyMe) = delete;
		HistsToShowCuts &operator=(HistsToShowCuts &&moveMe) = delete;

		TH1 *const strippingLevelDeltaMHist = new TH1D(_name_prefix + "stripping level DM", "DeltaM", 80, 138., 158.);
		TH1 *const strippingLevelMassHist = new TH1D(_name_prefix + "stripping level M", "M(K3Pi)", 120, 1800., 1920.);
		TH1 *const histDeltaM = new TH1D(_name_prefix + "Delta M", "with kProb cut", 80, 138., 158.);
		TH1 *const histDeltaM_selected = new TH1D(_name_prefix + "selected Delta M", "with kProb cut", 80, 138., 158.);
		TH1 *const cutsAMassHist = new TH1D(_name_prefix + "cutsA Mass hist", "cut on DeltaM", 120, 1800., 1920.);
		TH1 *const KminusKprobHist = new TH1D(_name_prefix + "K ProbNNk", "cutsA", 100, 0., 1.);
		TH1 *const massHistAlowKprob = new TH1D(_name_prefix + "low KProb", "cutsA", 120, 1800., 1920.);
		TH1 *const massHistAhighKprob = new TH1D(_name_prefix + "high KProb", "cutsA", 120, 1800., 1920.);
		TH1 *const d0MassHistSelected = new TH1D(_name_prefix + "selected_D0_mass_hist", "   ", 120, 1800., 1920.);
		TH1 *const d0barMassHistSelected = new TH1D(_name_prefix + "selected_D0bar_mass_hist", "   ", 120, 1800., 1920.);
		TH2D *const d0PhaseSpace = new TH2D(_name_prefix + "d0PhaseSpace", "p v pT", 8, 40000., 200000., 6, 4000., 16000.);
		TH2D *const d0barPhaseSpace = new TH2D(_name_prefix + "d0barPhaseSpace", "p v pT", 8, 40000., 200000., 6, 4000., 16000.);
		TH1 *const d0MassHist = new TH1D(_name_prefix + "D0_mass_hist", "   ", 120, 1800., 1920.);
		TH1 *const d0barMassHist = new TH1D(_name_prefix + "D0bar_mass_hist", "   ", 120, 1800., 1920.);
		TH1 *const massHistB = new TH1D(_name_prefix + "mass hist", "cuts B", 120, 1800., 1920.);
		TH2 *const thetaXY = new TH2D(_name_prefix + "thetaX,thetaY", "cuts B", 120, -0.3, 0.3, 120, -0.3, 0.3);
		TH1 *const testMassHist = new TH1D(_name_prefix + "test Mass hist", "cut on DeltaM", 120, 1800., 1920.);
		TH1 *const cutsCMassHist = new TH1D(_name_prefix + "cutsC Mass hist", "cut on DeltaM", 120, 1800., 1920.);
		TH2D *const rat = new TH2D(_name_prefix + "rat", "p v pT", 8, 40000., 200000., 6, 4000., 16000.);

		// the call to TFile->Close() in main in K3PiStudies.cpp seems to delete the hists so don't need this (BAD)
		/*virtual ~HistsToShowCuts() */
		/* { */
		/* 	delete strippingLevelDeltaMHist; */
		/* 	delete strippingLevelMassHist; */
		/* 	delete histDeltaM; */
		/* 	delete histDeltaM_selected; */
		/* 	delete cutsAMassHist; */
		/* 	delete KminusKprobHist; */
		/* 	delete massHistAlowKprob; */
		/* 	delete massHistAhighKprob; */
		/* 	delete d0MassHistSelected; */
		/* 	delete d0barMassHistSelected; */
		/* 	delete d0PhaseSpace; */
		/* 	delete d0barPhaseSpace; */
		/* 	delete d0MassHist; */
		/* 	delete d0barMassHist; */
		/* 	delete massHistB; */
		/* 	delete thetaXY; */
		/* 	delete testMassHist; */
		/* 	delete cutsCMassHist; */
		/* 	delete rat; */
		/* } */

		void saveHists(const TString &outputSubDir)
		{
			TCanvas c1;

			TLegend leg(0.12, 0.76, 0.32, 0.89);
			TPaveText pt2(0.70, 0.80, 0.90, 0.90, "NDC"); // NDC sets coords

			TString nd0Str;
			TString nd0barStr;

			gStyle->SetOptStat("rmen");

			strippingLevelDeltaMHist->Draw();
			c1.SaveAs(outputSubDir + "strippingLevelDeltaMHist.png");

			strippingLevelMassHist->Draw();
			c1.SaveAs(outputSubDir + "strippingLevelMassHist.png");

			cutsAMassHist->Draw();
			c1.SaveAs(outputSubDir + "cutsAMassHist.png");

			cutsCMassHist->Draw();
			c1.SaveAs(outputSubDir + "cutsCMassHist.png");

			testMassHist->Draw();
			c1.SaveAs(outputSubDir + "testMassHist.png");

			massHistB->Draw();
			c1.SaveAs(outputSubDir + "massHistB.png");

			thetaXY->Draw("COLZ");
			c1.SaveAs(outputSubDir + "thetaXY.png");

			KminusKprobHist->Draw();
			c1.SaveAs(outputSubDir + "KminusKprobHist.png");

			massHistAlowKprob->Draw();
			c1.SaveAs(outputSubDir + "massHistAlowKprob.png");

			massHistAhighKprob->Draw();
			c1.SaveAs(outputSubDir + "massHistAhighKprob.png");

			gStyle->SetOptStat(0);

			histDeltaM->GetXaxis()->SetTitleSize(0.06);
			histDeltaM->GetXaxis()->SetTitleOffset(0.75);
			histDeltaM->GetXaxis()->SetLabelFont(62);
			histDeltaM->GetXaxis()->CenterTitle(true);
			histDeltaM->SetTitle("#Delta(M)");
			histDeltaM->SetXTitle("#Delta(M) [MeV]");
			histDeltaM->GetYaxis()->SetTitleSize(0.06);
			histDeltaM->GetYaxis()->SetTitleOffset(0.75);
			histDeltaM->GetYaxis()->SetLabelFont(62);
			histDeltaM->SetYTitle("events per 250 keV");
			histDeltaM->SetLineColor(kBlue);
			histDeltaM->SetLineWidth(2);
			histDeltaM->Draw();
			histDeltaM_selected->SetFillColor(kGreen);
			histDeltaM_selected->SetFillStyle(1001);
			histDeltaM_selected->Draw("same");
			histDeltaM->Draw("same");
			c1.SaveAs(outputSubDir + "histDeltaM.png");

			d0MassHist->GetXaxis()->SetTitleSize(0.06);
			d0MassHist->GetXaxis()->SetTitleOffset(0.75);
			d0MassHist->GetXaxis()->SetLabelFont(62);
			d0MassHist->GetXaxis()->CenterTitle(true);
			d0MassHist->SetTitle("D^{0} Sample");
			d0MassHist->SetXTitle("mass(K#pi#pi#pi) [MeV]");
			d0MassHist->GetYaxis()->SetTitleSize(0.06);
			d0MassHist->GetYaxis()->SetTitleOffset(0.75);
			d0MassHist->GetYaxis()->SetLabelFont(62);
			d0MassHist->SetYTitle("events per  MeV");
			d0MassHist->SetLineColor(kBlue);
			d0MassHist->SetLineWidth(2);
			d0MassHist->Draw();
			d0MassHistSelected->SetFillColor(kGreen);
			d0MassHistSelected->SetFillStyle(1001);
			d0MassHistSelected->Draw("same");
			d0MassHist->Draw("same");
			c1.SaveAs(outputSubDir + "d0MassHist.png");

			d0barMassHist->GetXaxis()->SetTitleSize(0.06);
			d0barMassHist->GetXaxis()->SetTitleOffset(0.75);
			d0barMassHist->GetXaxis()->SetLabelFont(62);
			d0barMassHist->GetXaxis()->CenterTitle(true);
			d0barMassHist->SetTitle("#bar{D}^{0} Sample");
			d0barMassHist->SetXTitle("mass(K#pi#pi#pi) [MeV]");
			d0barMassHist->GetYaxis()->SetTitleSize(0.06);
			d0barMassHist->GetYaxis()->SetTitleOffset(0.75);
			d0barMassHist->GetYaxis()->SetLabelFont(62);
			d0barMassHist->SetYTitle("events per  MeV");
			d0barMassHist->SetLineColor(kBlue);
			d0barMassHist->SetLineWidth(2);
			d0barMassHist->Draw();
			d0barMassHistSelected->SetFillColor(kGreen);
			d0barMassHistSelected->SetFillStyle(1001);
			d0barMassHistSelected->Draw("same");
			d0barMassHist->Draw("same");
			c1.SaveAs(outputSubDir + "d0barMassHist.png");
			d0MassHist->Scale(1. / d0MassHist->GetEntries());
			d0MassHist->SetTitle("Compare D and #bar{D}");
			d0MassHist->SetYTitle("fraction per  MeV");
			d0barMassHist->Scale(1. / d0barMassHist->GetEntries());
			d0barMassHist->SetLineColor(kRed + 1);
			leg.Clear();
			leg.SetHeader("The Samples");
			leg.AddEntry(d0MassHist, "D^{0}", "L");
			leg.AddEntry(d0barMassHist, "#bar{D}^{0}", "L");
			d0MassHist->Draw();
			leg.Draw();
			d0MassHistSelected->Scale(1. / d0MassHist->GetEntries());
			d0MassHistSelected->SetFillColor(kGreen);
			d0MassHistSelected->SetFillStyle(1001);
			d0MassHistSelected->Draw("same");
			d0barMassHist->Draw("same");
			d0MassHist->Draw("same");
			nd0Str.Form("%6.0f\n", d0MassHist->GetEntries());
			nd0barStr.Form("%6.0f\n", d0barMassHist->GetEntries());
			pt2.AddText("n(D^{0}) = " + nd0Str);
			pt2.AddText("n(#bar{D}^{0}) = " + nd0barStr);
			pt2.Draw();
			c1.SaveAs(outputSubDir + "D_Dbar_Comparison.png");
			c1.SetLogy(1);
			c1.SaveAs(outputSubDir + "D_Dbar_ComparisonLogScale.png");
			c1.SetLogy(0);

			d0PhaseSpace->Draw("COLZ");
			c1.SaveAs(outputSubDir + "d0PhaseSpace.png");

			d0barPhaseSpace->Draw("COLZ");
			c1.SaveAs(outputSubDir + "d0barPhaseSpace.png");

			d0PhaseSpace->Sumw2();
			d0barPhaseSpace->Sumw2();
			rat->SetName("Ratio");
			rat->Divide(d0PhaseSpace, d0barPhaseSpace, 1., 1., "B");
			rat->Draw("COLZ");
			c1.SaveAs(outputSubDir + "phaseSpaceRatio.png");

			rat->SetFillColor(kYellow);
			rat->Draw("LEGO1 0");
			c1.SaveAs(outputSubDir + "phaseSpaceRatioLego.png");
		}
	}; // end class HistsToShowCuts

	class CommonHistsWithKinematics final
	{
	private:
		const TString _name_prefix;
		const double _D0_MASS_AXIS_MIN_MEV;
		const double _D0_MASS_AXIS_MAX_MEV;
		const double _DELTA_M_AXIS_MIN_MEV;
		const double _DELTA_M_AXIS_MAX_MEV;
		const TString _D0_MASS_YAXIS_LABEL;
		const TString _DELTA_M_YAXIS_LABEL;
		const TString _COMP_D0_MASS_YAXIS_LABEL;

	public:
		static const unsigned int _NUM_D0_MASS_BINS = 120;
		static const unsigned int _NUM_DELTA_M_BINS = 80;
		static const unsigned int _NUM_M_AB_BINS = 50;
		static const unsigned int _NUM_FINE_M_AB_BINS = 200;
		static const unsigned int _NUM_M_CD_BINS = 50;
		static const unsigned int _NUM_FINE_M_CD_BINS = 200;
		static constexpr double _M_AB_AXIS_MIN_MEV = 550.0;
		static constexpr double _M_AB_AXIS_MAX_MEV = 1300.0;
		static constexpr double _M_CD_AXIS_MIN_MEV = 200.0;
		static constexpr double _M_CD_AXIS_MAX_MEV = 1300.0;
		static const unsigned int _NUM_D0_DECAY_T_BINS = 80;
		static constexpr double _D0_DECAY_T_AXIS_MIN = 0.0;
		static constexpr double _D0_DECAY_T_AXIS_MAX = 10.0;
		static const unsigned int _NUM_PHI_BINS = 100;

		static inline const TString _D0_STR = "D^{0}";
		static inline const TString _D0_BAR_STR = "#bar{D^{0}}";
		static inline const TString _M_AB_LABEL = "m(K#pi_{low}) [MeV]";
		static inline const TString _M_CD_LABEL = "m(#pi^{-}#pi^{+}) [MeV]";
		static inline const TString _COS_THETA_A_LABEL = "cos(#theta_{A})";
		static inline const TString _COS_THETA_C_LABEL = "cos(#theta_{C})";
		static inline const TString _D0_MASS_LABEL = "m(D^{0}) [MeV]";
		static inline const TString _D0_BAR_MASS_LABEL = "m(#bar{D^{0}}) [MeV]";
		static inline const TString _KPIPIPI_MASS_LABEL = "m(K #pi #pi #pi) [MeV]";
		static inline const TString _DELTA_M_LABEL = "#Delta m [MeV]";
		static inline const TString _D0_DECAY_T_LABEL = "D^{0} decay time / #tau_{D^{0}}";

		static inline const TString _D0_MASS_YAXIS_LABEL_NO_ZOOM = K3PiStudiesUtils::makeYAxisLabel(_NUM_D0_MASS_BINS, K3PiStudiesUtils::_ALL_REGS_D0_MASS_AXIS_MIN_MEV, K3PiStudiesUtils::_ALL_REGS_D0_MASS_AXIS_MAX_MEV, "MeV", false);
		static inline const TString _DELTA_M_YAXIS_LABEL_NO_ZOOM = K3PiStudiesUtils::makeYAxisLabel(_NUM_DELTA_M_BINS, K3PiStudiesUtils::_ALL_REGS_DELTAM_AXIS_MIN_MEV, K3PiStudiesUtils::_ALL_REGS_DELTAM_AXIS_MAX_MEV, "MeV", false);

		CommonHistsWithKinematics(
			const TString &namePrefix,
			double d0MassAxisMinMeV,
			double d0MassAxisMaxMeV,
			double deltaMAxisMinMeV,
			double deltaMAxisMaxMeV) : _name_prefix(namePrefix),
									   _D0_MASS_AXIS_MIN_MEV(d0MassAxisMinMeV),
									   _D0_MASS_AXIS_MAX_MEV(d0MassAxisMaxMeV),
									   _DELTA_M_AXIS_MIN_MEV(deltaMAxisMinMeV),
									   _DELTA_M_AXIS_MAX_MEV(deltaMAxisMaxMeV),
									   _D0_MASS_YAXIS_LABEL(K3PiStudiesUtils::makeYAxisLabel(_NUM_D0_MASS_BINS, _D0_MASS_AXIS_MIN_MEV, _D0_MASS_AXIS_MAX_MEV, "MeV", false)),
									   _DELTA_M_YAXIS_LABEL(K3PiStudiesUtils::makeYAxisLabel(_NUM_DELTA_M_BINS, _DELTA_M_AXIS_MIN_MEV, _DELTA_M_AXIS_MAX_MEV, "MeV", false)),
									   _COMP_D0_MASS_YAXIS_LABEL(K3PiStudiesUtils::makeYAxisLabel(_NUM_D0_MASS_BINS, _D0_MASS_AXIS_MIN_MEV, _D0_MASS_AXIS_MAX_MEV, "MeV", true))
		{
			// std::cout << "Pre: " << _name_prefix << std::endl;
			// std::cout << "test name: " << mABmCD->GetName() << std::endl;
		}

		CommonHistsWithKinematics(const CommonHistsWithKinematics &copyMe) = delete;
		CommonHistsWithKinematics(CommonHistsWithKinematics &&moveMe) = delete;
		CommonHistsWithKinematics &operator=(const CommonHistsWithKinematics &copyMe) = delete;
		CommonHistsWithKinematics &operator=(CommonHistsWithKinematics &&moveMe) = delete;

		TH1D *const testPosSinPhi = new TH1D(
			_name_prefix + "testPosSinPhi",
			K3PiStudiesUtils::makeTitleStr("", "", ""),
			_NUM_PHI_BINS,
			0.0,
			1.0);
		TH1D *const testNegSinPhi = new TH1D(
			_name_prefix + "testNegSinPhi",
			K3PiStudiesUtils::makeTitleStr("", "", ""),
			_NUM_PHI_BINS,
			-1.0,
			0.0);
		TH1D *const testPosSin2Phi = new TH1D(
			_name_prefix + "testPosSin2Phi",
			K3PiStudiesUtils::makeTitleStr("", "", ""),
			_NUM_PHI_BINS,
			0.0,
			1.0);
		TH1D *const testNegSin2Phi = new TH1D(
			_name_prefix + "testNegSin2Phi",
			K3PiStudiesUtils::makeTitleStr("", "", ""),
			_NUM_PHI_BINS,
			-1.0,
			0.0);
		TH1D *const d0DecayTOverTau = new TH1D(
			_name_prefix + "d0DecayTOverTau",
			K3PiStudiesUtils::makeTitleStr("", _D0_DECAY_T_LABEL, K3PiStudiesUtils::makeYAxisLabel(_NUM_D0_DECAY_T_BINS, _D0_DECAY_T_AXIS_MIN, _D0_DECAY_T_AXIS_MAX, "", false)),
			_NUM_D0_DECAY_T_BINS,
			_D0_DECAY_T_AXIS_MIN,
			_D0_DECAY_T_AXIS_MAX);
		TH1D *const allDeltaMHist = new TH1D(
			_name_prefix + "allDeltaMHist",
			K3PiStudiesUtils::makeTitleStr("", _DELTA_M_LABEL, _DELTA_M_YAXIS_LABEL_NO_ZOOM),
			_NUM_DELTA_M_BINS,
			K3PiStudiesUtils::_ALL_REGS_DELTAM_AXIS_MIN_MEV,
			K3PiStudiesUtils::_ALL_REGS_DELTAM_AXIS_MAX_MEV);
		TH1D *const allMD0Hist = new TH1D(
			_name_prefix + "allMD0Hist",
			K3PiStudiesUtils::makeTitleStr("", _D0_MASS_LABEL, _D0_MASS_YAXIS_LABEL_NO_ZOOM),
			_NUM_D0_MASS_BINS,
			K3PiStudiesUtils::_ALL_REGS_D0_MASS_AXIS_MIN_MEV,
			K3PiStudiesUtils::_ALL_REGS_D0_MASS_AXIS_MAX_MEV);
		TH2D *const allMD0VDeltaMHist = new TH2D(
			_name_prefix + "allMD0VDeltaMHist",
			K3PiStudiesUtils::makeTitleStr("", _D0_MASS_LABEL, _DELTA_M_LABEL),
			_NUM_D0_MASS_BINS,
			_D0_MASS_AXIS_MIN_MEV,
			_D0_MASS_AXIS_MAX_MEV,
			_NUM_DELTA_M_BINS,
			_DELTA_M_AXIS_MIN_MEV,
			_DELTA_M_AXIS_MAX_MEV);
		TH1D *const d0OnlyMD0Hist = new TH1D(
			_name_prefix + "d0OnlyMD0Hist",
			K3PiStudiesUtils::makeTitleStr("", _KPIPIPI_MASS_LABEL, _COMP_D0_MASS_YAXIS_LABEL),
			_NUM_D0_MASS_BINS,
			_D0_MASS_AXIS_MIN_MEV,
			_D0_MASS_AXIS_MAX_MEV);
		TH1D *const d0BarOnlyMD0Hist = new TH1D(
			_name_prefix + "d0BarOnlyMD0Hist",
			K3PiStudiesUtils::makeTitleStr("", _KPIPIPI_MASS_LABEL, _COMP_D0_MASS_YAXIS_LABEL),
			_NUM_D0_MASS_BINS,
			_D0_MASS_AXIS_MIN_MEV,
			_D0_MASS_AXIS_MAX_MEV);
		TH2D *const mABmCD = new TH2D(
			_name_prefix + "mAB v mCD (passing cutsB)",
			";" + _M_AB_LABEL + ";" + _M_CD_LABEL,
			_NUM_M_AB_BINS,
			_M_AB_AXIS_MIN_MEV,
			_M_AB_AXIS_MAX_MEV,
			_NUM_M_CD_BINS,
			_M_CD_AXIS_MIN_MEV,
			_M_CD_AXIS_MAX_MEV);
		TH1D *const mAB = new TH1D(
			_name_prefix + "mAB",
			K3PiStudiesUtils::makeTitleStr("", _M_AB_LABEL, K3PiStudiesUtils::makeYAxisLabel(_NUM_M_AB_BINS, _M_AB_AXIS_MIN_MEV, _M_AB_AXIS_MAX_MEV, "MeV", false)),
			_NUM_M_AB_BINS,
			_M_AB_AXIS_MIN_MEV,
			_M_AB_AXIS_MAX_MEV);
		TH1D *const mCD = new TH1D(
			_name_prefix + "mCD",
			K3PiStudiesUtils::makeTitleStr("", _M_CD_LABEL, K3PiStudiesUtils::makeYAxisLabel(_NUM_M_CD_BINS, _M_CD_AXIS_MIN_MEV, _M_CD_AXIS_MAX_MEV, "MeV", false)),
			_NUM_M_CD_BINS,
			_M_CD_AXIS_MIN_MEV,
			_M_CD_AXIS_MAX_MEV);
		TH2D *const mKPimPiPi = new TH2D(_name_prefix + "mKPi v mPiPi (passing cutsB)", ";" + _M_AB_LABEL + ";" + _M_CD_LABEL, 50, 550, 1550, 50, 200., 1300.);
		TH1 *const mCDforKstar = new TH1D(_name_prefix + "mCD for Kstar Region", ";" + _M_CD_LABEL, 110, 200., 1300.);
		TH1 *const mCDforLowKPiMass = new TH1D(_name_prefix + "mCD for low K,pi mass", ";" + _M_CD_LABEL, 110, 200., 1300.);
		TH1 *const mABforRhoZero = new TH1D(_name_prefix + "mAB for Rho Region", ";" + _M_AB_LABEL, 70, 550, 1250);
		TH2D *const cosVsinPlot = new TH2D(_name_prefix + "cos phi v sin phi Sanity Plot", ";cos(#phi);sin(#phi)", 50, -1.5, 1.5, 50, -1.5, 1.5);
		TH1 *const allPhiHist = new TH1D(_name_prefix + "Phi (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const allPhiHistD0 = new TH1D(_name_prefix + "Phi for D0 (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const allPhiHistD0bar = new TH1D(_name_prefix + "Phi for D0bar (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1D *const cosThetaAHist = new TH1D(_name_prefix + "cosThetaA (passing cuts B)", ";" + _COS_THETA_A_LABEL, 100, -1., 1.);
		TH1D *const cosThetaCHist = new TH1D(_name_prefix + "cosThetaC (passing cuts B)", ";" + _COS_THETA_C_LABEL, 100, -1., 1.);
		TH2D *const cosThetaAcosThetaCHist = new TH2D(_name_prefix + "cosThetaA v cosThetaC (passing cutsB)", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD02KstarRho = new TH1D(_name_prefix + "Phi for D02KstarRho (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD02KstarRho = new TH1D(_name_prefix + "Quad1 phi for D02KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD02KstarRho = new TH1D(_name_prefix + "Quad2 phi for D02KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD02KstarRho = new TH1D(_name_prefix + "Quad3 phi for D02KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD02KstarRho = new TH1D(_name_prefix + "Quad4 phi for D02KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD02KstarRho = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0 at KstarRho", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD0bar2KstarRho = new TH1D(_name_prefix + "Phi for D0bar2KstarRho (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD0bar2KstarRho = new TH1D(_name_prefix + "Quad1 phi for D0bar2KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD0bar2KstarRho = new TH1D(_name_prefix + "Quad2 phi for D0bar2KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD0bar2KstarRho = new TH1D(_name_prefix + "Quad3 phi for D0bar2KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD0bar2KstarRho = new TH1D(_name_prefix + "Quad4 phi for D0bar2KstarRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD0bar2KstarRho = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0bar at KstarRho", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD02KstarF0 = new TH1D(_name_prefix + "Phi for D02KstarF0 (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD02KstarF0 = new TH1D(_name_prefix + "Quad1 phi for D02KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD02KstarF0 = new TH1D(_name_prefix + "Quad2 phi for D02KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD02KstarF0 = new TH1D(_name_prefix + "Quad3 phi for D02KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD02KstarF0 = new TH1D(_name_prefix + "Quad4 phi for D02KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD02KstarF0 = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0 at KstarF0", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD0bar2KstarF0 = new TH1D(_name_prefix + "Phi for D0bar2KstarF0 (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD0bar2KstarF0 = new TH1D(_name_prefix + "Quad1 phi for D0bar2KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD0bar2KstarF0 = new TH1D(_name_prefix + "Quad2 phi for D0bar2KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD0bar2KstarF0 = new TH1D(_name_prefix + "Quad3 phi for D0bar2KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD0bar2KstarF0 = new TH1D(_name_prefix + "Quad4 phi for D0bar2KstarF0", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD0bar2KstarF0 = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0bar at KstarF0", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD02KappaRho = new TH1D(_name_prefix + "Phi for D02KappaRho (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD02KappaRho = new TH1D(_name_prefix + "Quad1 phi for D02KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD02KappaRho = new TH1D(_name_prefix + "Quad2 phi for D02KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD02KappaRho = new TH1D(_name_prefix + "Quad3 phi for D02KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD02KappaRho = new TH1D(_name_prefix + "Quad4 phi for D02KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD02KappaRho = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0 at KappaRho", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiHistD0bar2KappaRho = new TH1D(_name_prefix + "Phi for D0bar2KappaRho (passing cutsB)", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad1PhiHistD0bar2KappaRho = new TH1D(_name_prefix + "Quad1 phi for D0bar2KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad2PhiHistD0bar2KappaRho = new TH1D(_name_prefix + "Quad2 phi for D0bar2KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad3PhiHistD0bar2KappaRho = new TH1D(_name_prefix + "Quad3 phi for D0bar2KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH1 *const quad4PhiHistD0bar2KappaRho = new TH1D(_name_prefix + "Quad4 phi for D0bar2KappaRho", ";#phi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const tAtCD0bar2KappaRho = new TH2D(_name_prefix + "cosThetaA v cosThetaC for D0bar at KappaRho", ";" + _COS_THETA_A_LABEL + ";" + _COS_THETA_C_LABEL, 100, -1., 1., 100, -1., 1.);
		TH1 *const allPhiAHist = new TH1D(_name_prefix + "phi", "cutsB; low-mass K,pi", _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const cosVsinPlotA = new TH2D(_name_prefix + "cosine v sine", "sanity plotA ", 50, -1.5, 1.5, 50, -1.5, 1.5);
		TH2D *const mABmCDForLowKPiPi = new TH2D(_name_prefix + "mAB_v_mCD for Low KPiPi", "passing cutsB", 50, 550, 1300., 50, 200., 1300.);
		TH2D *const mADmCB = new TH2D(_name_prefix + "mAD_v_mCB", "passing cutsB", 50, 550, 1550, 50, 200., 1300.);
		TH2D *const mABmAD = new TH2D(_name_prefix + "mAB_v_mAD", "passing cutsB", 50, 550, 1550, 50, 550., 1550.);
		TH2D *const mABmADForKappaRho = new TH2D(_name_prefix + "mAB_v_mA, for Kappa RhoD", "passing cutsB", 50, 550, 1550, 50, 550., 1550.);
		TH2D *const mABmADForKstarRho = new TH2D(_name_prefix + "mAB_v_mAD, K*Rho", "passing cutsB", 50, 550, 1550, 50, 550., 1550.);
		TH2D *const mABmADForKstarF0 = new TH2D(_name_prefix + "mAB_v_mAD, K* f0", "passing cutsB", 50, 550, 1550, 50, 550., 1550.);
		TH2D *const mABmADzoomed = new TH2D(_name_prefix + "mAB_v_mAD zoomedin", "passing cutsB", 25, 600, 850, 25, 600., 850.);
		TH1D *const mPiPiForLowKPiPi = new TH1D(_name_prefix + "mPiPi", "for low KPiPi mass", 100, 280., 780.);
		TH1D *const mABD_corner = new TH1D(_name_prefix + "mABD_corner", "m(K,pi+,pi+) in the corner", 120, 750., 1350.);
		TH1D *const cornerPiPlusPiPlusMassHist = new TH1D(_name_prefix + "mPiPlusPiPlus corner", "for low KPiPi mass", 100, 280., 1280.);
		TH1D *const cornerPiMinusPiPlusMassHist = new TH1D(_name_prefix + "mPiMinusPiPlus corner", "for low KPiPi mass", 100, 280., 1280.);
		TH1D *const cornerKMinusPiMinusMassHist = new TH1D(_name_prefix + "mKMinusPiMinus corner", "for low KPiPi mass", 100, 600., 1600.);
		TH1D *const cornerKMinusPiPlusMassHist = new TH1D(_name_prefix + "mKMinusPiPlus corner", "for low KPiPi mass", 100, 600., 1600.);
		TH1D *const cornerKMinusEnergyHist = new TH1D(_name_prefix + "eKMinus corner", "for low KPiPi mass", 100, 400., 900.);
		TH1D *const cornerPiMinusEnergyHist = new TH1D(_name_prefix + "ePiMinus corner", "for low KPiPi mass", 120, 400., 1000.);
		TH1D *const cornerPiPlusEnergyHist = new TH1D(_name_prefix + "ePiPlus corner", "for low KPiPi mass", 100, 100., 600.);
		TH1D *const cornerKMinusPzHist = new TH1D(_name_prefix + "pzKMinus corner", "for low KPiPi mass", 100, -1000., 1000.);
		TH1D *const cornerPiMinusPzHist = new TH1D(_name_prefix + "pzPiMinus corner", "for low KPiPi mass", 100, -1000., 1000.);
		TH1D *const cornerPiPlusPzHist = new TH1D(_name_prefix + "pzPiPlus corner", "for low KPiPi mass", 100, -1000., 1000.);
		TH1D *const cornerKPiPiMassSqHist = new TH1D(_name_prefix + "KPiPi massSq corner", "for low KPiPi mass", 100, 0.4, 3.4);
		TH1D *const KPiPiMassSqHist = new TH1D(_name_prefix + "KPiPi massSq", "for cutsB", 100, 0.4, 3.4);
		TH1D *const cornerKminusHelictyCosineHist = new TH1D(_name_prefix + "KminusHelictyCosineHist corner", "in the corner", 100, -1., 1.);
		TH1D *const KmPipPipAllHist = new TH1D(_name_prefix + "all cutsB events", "mK-Pi+Pi+", 100, 750., 1750.);
		TH1D *const KmPipPipNotKstarRhoCand = new TH1D(_name_prefix + " cutsB, not K*Rho", "mK-Pi+Pi+", 100, 750., 1750.);
		TH1D *const piMinusEnergyHist = new TH1D(_name_prefix + "pi_minus_energy", "passing cutsB", 80, 100., 900.);
		TH1D *const piMinusEnergyHistD0 = new TH1D(_name_prefix + "pi_minus_energy_D0", "passing cutsB", 80, 100., 900.);
		TH1D *const piMinusEnergyHistD0bar = new TH1D(_name_prefix + "pi_minus_energy_D0bar", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusBEnergyHist = new TH1D(_name_prefix + "pi_plusB_energy", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusBEnergyHistD0 = new TH1D(_name_prefix + "pi_plusB_energy_D0", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusBEnergyHistD0bar = new TH1D(_name_prefix + "pi_plusB_energy_D0bar", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusDEnergyHist = new TH1D(_name_prefix + "pi_plusD_energy", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusDEnergyHistD0 = new TH1D(_name_prefix + "pi_plusD_energy_D0", "passing cutsB", 80, 100., 900.);
		TH1D *const piPlusDEnergyHistD0bar = new TH1D(_name_prefix + "pi_plusD_energy_D0bar", "passing cutsB", 80, 100., 900.);
		TH1D *const KMinusEnergyHist = new TH1D(_name_prefix + "K_minus_energy", "passing cutsB", 120, 400., 1000.);
		TH1D *const KMinusEnergyHistD0 = new TH1D(_name_prefix + "K_minus_energy_D0", "passing cutsB", 120, 400., 1000.);
		TH1D *const KMinusEnergyHistD0bar = new TH1D(_name_prefix + "K_minus_energy_D0bar", "passing cutsB", 120, 400., 1000.);
		TH2D *const KstarPiPiDP1213 = new TH2D(_name_prefix + "K*,pi-,pi+ DP, s12,s13", "K* +- 50 MeV", 50, 1.0, 2.8, 50, 1.0, 2.8);
		TH2D *const KstarPiPiDP2313 = new TH2D(_name_prefix + "K*,pi-,pi+ DP, s23,s13", "K* +- 50 MeV", 50, 0.0, 1.2, 50, 1.0, 2.8);
		TH2D *const KstarPiPiDP2312 = new TH2D(_name_prefix + "K*,pi-,pi+ DP, s23,s12", "K* +- 50 MeV", 50, 0.0, 1.2, 50, 1.0, 2.8);
		TH2D *const sanityPlot = new TH2D(_name_prefix + "for all events", "tripleProduct v phi", 100, -600., 600., _NUM_PHI_BINS, 0., 2.0 * K3PiStudiesUtils::_PI);
		TH2D *const mKPimPiPiA = new TH2D(_name_prefix + "at higher decay time", "mKPi v mPiPi", 50, 550, 1550, 50, 200., 1300.);

		// the call to TFile->Close() in main in K3PiStudies.cpp seems to delete the hists so don't need this (BAD)
		/* virtual ~CommonHistsWithKinematics() */
		/* { */
		/* 	delete mABmCD; */
		/* 	delete mKPimPiPi; */
		/* 	delete mCDforKstar; */
		/* 	delete mCDforLowKPiMass; */
		/* 	delete mABforRhoZero; */
		/* 	delete cosVsinPlot; */
		/* 	delete allPhiHist; */
		/* 	delete allPhiHistD0; */
		/* 	delete allPhiHistD0bar; */
		/* 	delete cosThetaAHist; */
		/* 	delete cosThetaCHist; */
		/* 	delete cosThetaAcosThetaCHist; */
		/* 	delete allPhiHistD02KstarRho; */
		/* 	delete quad1PhiHistD02KstarRho; */
		/* 	delete quad2PhiHistD02KstarRho; */
		/* 	delete quad3PhiHistD02KstarRho; */
		/* 	delete quad4PhiHistD02KstarRho; */
		/* 	delete tAtCD02KstarRho; */
		/* 	delete allPhiHistD0bar2KstarRho; */
		/* 	delete quad1PhiHistD0bar2KstarRho; */
		/* 	delete quad2PhiHistD0bar2KstarRho; */
		/* 	delete quad3PhiHistD0bar2KstarRho; */
		/* 	delete quad4PhiHistD0bar2KstarRho; */
		/* 	delete tAtCD0bar2KstarRho; */
		/* 	delete allPhiHistD02KstarF0; */
		/* 	delete quad1PhiHistD02KstarF0; */
		/* 	delete quad2PhiHistD02KstarF0; */
		/* 	delete quad3PhiHistD02KstarF0; */
		/* 	delete quad4PhiHistD02KstarF0; */
		/* 	delete tAtCD02KstarF0; */
		/* 	delete allPhiHistD0bar2KstarF0; */
		/* 	delete quad1PhiHistD0bar2KstarF0; */
		/* 	delete quad2PhiHistD0bar2KstarF0; */
		/* 	delete quad3PhiHistD0bar2KstarF0; */
		/* 	delete quad4PhiHistD0bar2KstarF0; */
		/* 	delete tAtCD0bar2KstarF0; */
		/* 	delete allPhiHistD02KappaRho; */
		/* 	delete quad1PhiHistD02KappaRho; */
		/* 	delete quad2PhiHistD02KappaRho; */
		/* 	delete quad3PhiHistD02KappaRho; */
		/* 	delete quad4PhiHistD02KappaRho; */
		/* 	delete tAtCD02KappaRho; */
		/* 	delete allPhiHistD0bar2KappaRho; */
		/* 	delete quad1PhiHistD0bar2KappaRho; */
		/* 	delete quad2PhiHistD0bar2KappaRho; */
		/* 	delete quad3PhiHistD0bar2KappaRho; */
		/* 	delete quad4PhiHistD0bar2KappaRho; */
		/* 	delete tAtCD0bar2KappaRho; */
		/* 	delete allPhiAHist; */
		/* 	delete cosVsinPlotA; */
		/* 	delete mABmCDForLowKPiPi; */
		/* 	delete mADmCB; */
		/* 	delete mABmAD; */
		/* 	delete mABmADForKappaRho; */
		/* 	delete mABmADForKstarRho; */
		/* 	delete mABmADForKstarF0; */
		/* 	delete mABmADzoomed; */
		/* 	delete mPiPiForLowKPiPi; */
		/* 	delete mABD_corner; */
		/* 	delete cornerPiPlusPiPlusMassHist; */
		/* 	delete cornerPiMinusPiPlusMassHist; */
		/* 	delete cornerKMinusPiMinusMassHist; */
		/* 	delete cornerKMinusPiPlusMassHist; */
		/* 	delete cornerPiMinusEnergyHist; */
		/* 	delete cornerPiPlusEnergyHist; */
		/* 	delete cornerKMinusPzHist; */
		/* 	delete cornerPiMinusPzHist; */
		/* 	delete cornerPiPlusPzHist; */
		/* 	delete cornerKPiPiMassSqHist; */
		/* 	delete KPiPiMassSqHist; */
		/* 	delete cornerKminusHelictyCosineHist; */
		/* 	delete  KmPipPipAllHist; */
		/* 	delete  KmPipPipNotKstarRhoCand; */
		/* 	delete piMinusEnergyHist; */
		/* 	delete piMinusEnergyHistD0; */
		/* 	delete piMinusEnergyHistD0bar; */
		/* 	delete piPlusBEnergyHist; */
		/* 	delete piPlusBEnergyHistD0; */
		/* 	delete piPlusBEnergyHistD0bar; */
		/* 	delete piPlusDEnergyHist; */
		/* 	delete piPlusDEnergyHistD0; */
		/* 	delete piPlusDEnergyHistD0bar; */
		/* 	delete KMinusEnergyHist; */
		/* 	delete KMinusEnergyHistD0; */
		/* 	delete KMinusEnergyHistD0bar; */
		/* 	delete KstarPiPiDP1213; */
		/* 	delete KstarPiPiDP2313; */
		/* 	delete KstarPiPiDP2312; */
		/* 	delete sanityPlot; */
		/* 	delete mKPimPiPiA; */
		/* } */

		void saveHists(const TString &outputSubDir)
		{
			TCanvas c1;

			gStyle->SetOptStat("rme");

			testPosSinPhi->Draw();
			c1.SaveAs(outputSubDir + "testPosSinPhi.png");

			testNegSinPhi->Draw();
			c1.SaveAs(outputSubDir + "testNegSinPhi.png");

			testPosSin2Phi->Draw();
			c1.SaveAs(outputSubDir + "testPosSin2Phi.png");

			testNegSin2Phi->Draw();
			c1.SaveAs(outputSubDir + "testNegSin2Phi.png");

			mAB->Draw();
			c1.SaveAs(outputSubDir + "mAB.png");

			mCD->Draw();
			c1.SaveAs(outputSubDir + "mCD.png");

			d0DecayTOverTau->Draw();
			c1.SaveAs(outputSubDir + "d0DecayTOverTau.png");
			// semilog
			c1.SetLogy(1);
			c1.SaveAs(outputSubDir + "d0DecayTOverTau_semilog.png");
			c1.SetLogy(0);

			cosThetaAHist->Draw();
			c1.SaveAs(outputSubDir + "cosThetaAHist.png");

			cosThetaCHist->Draw();
			c1.SaveAs(outputSubDir + "cosThetaCHist.png");

			allMD0Hist->Draw();
			c1.SaveAs(outputSubDir + "allMD0Hist.png");

			allDeltaMHist->Draw();
			c1.SaveAs(outputSubDir + "allDeltaMHist.png");

			allPhiHist->Draw();
			c1.SaveAs(outputSubDir + "allPhiHist.png");

			allPhiHistD0->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD0.png");

			allPhiHistD0bar->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD0bar.png");

			Double_t d02KstarRhoEntries = allPhiHistD02KstarRho->GetEntries();
			Double_t d0bar2KstarRhoEntries = allPhiHistD0bar2KstarRho->GetEntries();
			if (d02KstarRhoEntries != 0 && d0bar2KstarRhoEntries != 0)
			{
				allPhiHistD02KstarRho->SetLineColor(kBlue);
				allPhiHistD02KstarRho->SetLineWidth(2);
				allPhiHistD02KstarRho->Scale(1.00 / d02KstarRhoEntries);
				allPhiHistD02KstarRho->Draw();
				allPhiHistD0bar2KstarRho->SetLineColor(kRed + 1);
				allPhiHistD0bar2KstarRho->SetLineWidth(2);
				allPhiHistD0bar2KstarRho->Scale(1.00 / d0bar2KstarRhoEntries);
				allPhiHistD0bar2KstarRho->Draw("same");
				c1.SaveAs(outputSubDir + "comparePhiKstarRho.png");
			}

			gStyle->SetOptStat(1111);

			cosVsinPlotA->Draw();
			c1.SaveAs(outputSubDir + "cosVsinPlot.png");

			allPhiHistD02KstarRho->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD02KstarRho.png");

			allPhiHistD0bar2KstarRho->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD0bar2KstarRho.png");

			mCDforKstar->Draw();
			c1.SaveAs(outputSubDir + "mCDforKstar.png");

			mCDforLowKPiMass->Draw();
			c1.SaveAs(outputSubDir + "mCDforLowKPiMass.png");

			mABforRhoZero->Draw();
			c1.SaveAs(outputSubDir + "mABforRhoZero.png");

			cosVsinPlot->Draw();
			c1.SaveAs(outputSubDir + "cosVsinPlot.png");

			gStyle->SetOptStat(0);

			K3PiStudiesUtils::makeNormalizedComparisonPlot(
				d0OnlyMD0Hist,
				d0BarOnlyMD0Hist,
				_D0_STR,
				_D0_BAR_STR,
				true,
				outputSubDir + "compareMD0.png",
				"",
				false);

			allMD0VDeltaMHist->Draw("COLZ");
			c1.SaveAs(outputSubDir + "allMD0VDeltaMHist.png");
			// log color scale
			gPad->SetLogz(1);
			c1.SaveAs(outputSubDir + "allMD0VDeltaMHist_logColor.png");
			gPad->SetLogz(0);
			// capped linear scale
			double allMD0VDeltaMHistMax = allMD0VDeltaMHist->GetMaximum();
			allMD0VDeltaMHist->SetMaximum(allMD0VDeltaMHistMax / 10.0);
			allMD0VDeltaMHist->Draw("COLZ");
			c1.SaveAs(outputSubDir + "allMD0VDeltaMHist_capped.png");
			allMD0VDeltaMHist->SetMaximum(allMD0VDeltaMHistMax);

			mABmAD->GetXaxis()->SetTitleSize(0.05);
			mABmAD->GetXaxis()->SetTitleOffset(0.90);
			mABmAD->GetXaxis()->SetLabelFont(62);
			mABmAD->GetXaxis()->SetLabelSize(0.04);
			mABmAD->GetXaxis()->CenterTitle(true);
			mABmAD->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
			mABmAD->SetXTitle("mass(K#pi)_{low} [MeV]");
			mABmAD->GetYaxis()->SetTitleSize(0.05);
			mABmAD->GetYaxis()->SetLabelSize(0.04);
			mABmAD->GetYaxis()->SetTitleOffset(0.90);
			mABmAD->GetYaxis()->SetLabelFont(62);
			mABmAD->SetYTitle("mass(K#pi)_{high} [MeV]");
			mABmAD->SetLineColor(kBlue);
			mABmAD->SetLineWidth(2);
			mABmAD->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmAD.png");

			mABmADzoomed->GetXaxis()->SetTitleSize(0.05);
			mABmADzoomed->GetXaxis()->SetTitleOffset(0.90);
			mABmADzoomed->GetXaxis()->SetLabelFont(62);
			mABmADzoomed->GetXaxis()->SetLabelSize(0.04);
			mABmADzoomed->GetXaxis()->CenterTitle(true);
			mABmADzoomed->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
			mABmADzoomed->SetXTitle("mass(K#pi)_{low} [MeV]");
			mABmADzoomed->GetYaxis()->SetTitleSize(0.05);
			mABmADzoomed->GetYaxis()->SetLabelSize(0.04);
			mABmADzoomed->GetYaxis()->SetTitleOffset(0.90);
			mABmADzoomed->GetYaxis()->SetLabelFont(62);
			mABmADzoomed->SetYTitle("mass(K#pi)_{high} [MeV]");
			mABmADzoomed->SetLineColor(kBlue);
			mABmADzoomed->SetLineWidth(2);
			mABmADzoomed->Draw("COLZ");
			mABmADzoomed->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmADzoomed.png");

			mABmADzoomed->SetFillColor(kYellow);
			mABmADzoomed->Draw("LEGO1 0");
			c1.SaveAs(outputSubDir + "mABmADzoomedLego.png");

			mKPimPiPiA->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mKPimPiPiA.png");

			mKPimPiPiA->SetFillColor(kYellow);
			mKPimPiPiA->Draw("LEGO1 0");
			c1.SaveAs(outputSubDir + "mKPimPiPiALego.png");

			mKPimPiPiA->Draw("SURF1");
			c1.SaveAs(outputSubDir + "mKPimPiPiASurf1.png");

			mKPimPiPiA->Draw("SURF3");
			c1.SaveAs(outputSubDir + "mKPimPiPiASurf3.png");

			KstarPiPiDP1213->Draw("SURF1");
			c1.SaveAs(outputSubDir + "KstarPiPiDP1213Surf1.png");

			KstarPiPiDP1213->Draw("COLZ");
			c1.SaveAs(outputSubDir + "KstarPiPiDP1213.png");

			KstarPiPiDP2313->Draw("SURF1");
			c1.SaveAs(outputSubDir + "KstarPiPiDP2313Surf1.png");

			KstarPiPiDP2313->Draw("COLZ");
			c1.SaveAs(outputSubDir + "KstarPiPiDP2313.png");

			KstarPiPiDP2312->Draw("SURF1");
			c1.SaveAs(outputSubDir + "KstarPiPiDP2312Surf1.png");

			KstarPiPiDP2312->Draw("COLZ");
			c1.SaveAs(outputSubDir + "KstarPiPiDP2312.png");

			sanityPlot->Draw("COLZ");
			c1.SaveAs(outputSubDir + "sanityPlot.png");

			mABD_corner->Draw();
			c1.SaveAs(outputSubDir + "mABD_corner.png");

			mPiPiForLowKPiPi->GetXaxis()->SetTitleSize(0.05);
			mPiPiForLowKPiPi->GetXaxis()->SetTitleOffset(0.90);
			mPiPiForLowKPiPi->GetXaxis()->SetLabelFont(62);
			mPiPiForLowKPiPi->GetXaxis()->SetLabelSize(0.04);
			mPiPiForLowKPiPi->GetXaxis()->CenterTitle(true);
			mPiPiForLowKPiPi->SetTitle("m(#pi^{+}#pi^{+}) for low M(K^{-}#pi^{+}#pi^{+})}");
			mPiPiForLowKPiPi->SetXTitle("mass(#pi^{+}#pi^{+})     [MeV]");
			mPiPiForLowKPiPi->GetYaxis()->SetTitleSize(0.05);
			mPiPiForLowKPiPi->GetYaxis()->SetLabelSize(0.04);
			mPiPiForLowKPiPi->GetYaxis()->SetTitleOffset(0.90);
			mPiPiForLowKPiPi->GetYaxis()->SetLabelFont(62);
			mPiPiForLowKPiPi->SetYTitle(" events per 5 MeV");
			mPiPiForLowKPiPi->SetLineColor(kBlue);
			mPiPiForLowKPiPi->SetLineWidth(2);
			mPiPiForLowKPiPi->Draw();
			c1.SaveAs(outputSubDir + "mPiPiForLowKPiPi.png");

			mABmCDForLowKPiPi->GetXaxis()->SetTitleSize(0.05);
			mABmCDForLowKPiPi->GetXaxis()->SetTitleOffset(0.90);
			mABmCDForLowKPiPi->GetXaxis()->SetLabelFont(62);
			mABmCDForLowKPiPi->GetXaxis()->SetLabelSize(0.04);
			mABmCDForLowKPiPi->GetXaxis()->CenterTitle(true);
			mABmCDForLowKPiPi->SetTitle("m(K#pi)_{low} v. m(K#pi)_{high}");
			mABmCDForLowKPiPi->SetXTitle("mass(K#pi)_{low} [MeV]");
			mABmCDForLowKPiPi->GetYaxis()->SetTitleSize(0.05);
			mABmCDForLowKPiPi->GetYaxis()->SetLabelSize(0.04);
			mABmCDForLowKPiPi->GetYaxis()->SetTitleOffset(0.90);
			mABmCDForLowKPiPi->GetYaxis()->SetLabelFont(62);
			mABmCDForLowKPiPi->SetYTitle("mass(#pi^{-}#pi^{+})_{high} [MeV]");
			mABmCDForLowKPiPi->SetLineColor(kBlue);
			mABmCDForLowKPiPi->SetLineWidth(2);
			mABmCDForLowKPiPi->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmCDForLowKPiPi.png");

			mABmADForKstarRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmADForKstarRho.png");

			mABmADForKstarF0->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmADForKstarF0.png");

			mABmADForKappaRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmADForKappaRho.png");

			piMinusEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "piMinusEnergyHist.png");

			piMinusEnergyHistD0->Draw();
			c1.SaveAs(outputSubDir + "piMinusEnergyHistD0.png");

			piMinusEnergyHistD0bar->Draw();
			c1.SaveAs(outputSubDir + "piMinusEnergyHistD0bar.png");

			piPlusBEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "piPlusBEnergyHist.png");

			piPlusBEnergyHistD0->Draw();
			c1.SaveAs(outputSubDir + "piPlusBEnergyHistD0.png");

			piPlusBEnergyHistD0bar->Draw();
			c1.SaveAs(outputSubDir + "piPlusBEnergyHistD0bar.png");

			piPlusDEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "piPlusDEnergyHist.png");

			piPlusDEnergyHistD0->Draw();
			c1.SaveAs(outputSubDir + "piPlusDEnergyHistD0.png");

			piPlusDEnergyHistD0bar->Draw();
			c1.SaveAs(outputSubDir + "piPlusDEnergyHistD0bar.png");

			TH1D piPlusEnergyHist = *piPlusBEnergyHist + *piPlusDEnergyHist;
			piPlusEnergyHist.SetNameTitle("piPlusEnergyHist", "sum of piPlusB and piPlusD");
			piPlusEnergyHist.Draw();
			c1.SaveAs(outputSubDir + "piPlusEnergyHist.png");

			TH1D piPlusEnergyHistD0 = *piPlusBEnergyHistD0 + *piPlusDEnergyHistD0;
			piPlusEnergyHistD0.SetNameTitle("piPlusEnergyHistD0", "sum of piPlusB and piPlusD");
			piPlusEnergyHistD0.Draw();
			c1.SaveAs(outputSubDir + "piPlusEnergyHistD0.png");

			TH1D piPlusEnergyHistD0bar = *piPlusBEnergyHistD0bar + *piPlusDEnergyHistD0bar;
			piPlusEnergyHistD0bar.SetNameTitle("piPlusEnergyHistD0bar", "sum of piPlusB and piPlusD");
			piPlusEnergyHistD0bar.Draw();
			c1.SaveAs(outputSubDir + "piPlusEnergyHistD0bar.png");

			KMinusEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "KMinusEnergyHist.png");

			KMinusEnergyHistD0->Draw();
			c1.SaveAs(outputSubDir + "KMinusEnergyHistD0.png");

			KMinusEnergyHistD0bar->Draw();
			c1.SaveAs(outputSubDir + "KMinusEnergyHistD0bar.png");

			KmPipPipAllHist->Draw();
			c1.SaveAs(outputSubDir + "KmPipPipAllHist.png");

			KmPipPipNotKstarRhoCand->Draw();
			c1.SaveAs(outputSubDir + "KmPipPipNostKstarRhoCand.png");

			cornerKMinusEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKMinusEnergyHist.png");

			cornerPiMinusEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiMinusEnergyHist.png");

			cornerPiPlusEnergyHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiPlusEnergyHist.png");

			cornerKMinusPiMinusMassHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKMinusPiMinusMassHist.png");

			cornerKMinusPiPlusMassHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKMinusPiPlusMassHist.png");

			cornerPiMinusPiPlusMassHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiMinusPiPlusMassHist.png");

			cornerPiPlusPiPlusMassHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiPlusPiPlusMassHist.png");

			cornerKMinusPzHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKMinusPzHist.png");

			cornerPiMinusPzHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiMinusPzHist.png");

			cornerPiPlusPzHist->Draw();
			c1.SaveAs(outputSubDir + "cornerPiPlusPzHist.png");

			cornerKPiPiMassSqHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKPiPiMassSqHist.png");

			KPiPiMassSqHist->Draw();
			c1.SaveAs(outputSubDir + "KPiPiMassSqHist.png");

			cornerKminusHelictyCosineHist->Draw();
			c1.SaveAs(outputSubDir + "cornerKminusHelictyCosineHist.png");

			gStyle->SetOptStat("e");

			mABmCD->GetXaxis()->SetTitleSize(0.05);
			mABmCD->GetXaxis()->SetTitleOffset(0.90);
			mABmCD->GetXaxis()->SetLabelFont(62);
			mABmCD->GetXaxis()->SetLabelSize(0.04);
			mABmCD->GetXaxis()->CenterTitle(true);
			mABmCD->SetTitle(""); //(_M_AB_LABEL + " v. " + _M_CD_LABEL);
			mABmCD->SetXTitle(_M_AB_LABEL);
			mABmCD->GetYaxis()->SetTitleSize(0.05);
			mABmCD->GetYaxis()->SetLabelSize(0.04);
			mABmCD->GetYaxis()->SetTitleOffset(0.90);
			mABmCD->GetYaxis()->SetLabelFont(62);
			mABmCD->SetYTitle(_M_CD_LABEL);
			mABmCD->SetLineColor(kBlue);
			mABmCD->SetLineWidth(2);
			mABmCD->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmCD.png");
			gPad->SetLogz(1);
			c1.SaveAs(outputSubDir + "mABmCD_logColor.png");
			gPad->SetLogz(0);

			Double_t temp = mABmCD->GetMaximum();
			mABmCD->SetMaximum(temp / 3.);
			mABmCD->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mABmCD_capped.png");
			mABmCD->SetMaximum(temp);

			gStyle->SetOptStat(0);

			mABmCD->GetXaxis()->SetTitleOffset(1.50);
			mABmCD->GetYaxis()->SetTitleOffset(1.50);
			mABmCD->Draw("SURF1");
			c1.SaveAs(outputSubDir + "mABmCDSurf1.png");

			mKPimPiPi->Draw("COLZ");
			c1.SaveAs(outputSubDir + "mKPimPiPi.png");

			mKPimPiPi->SetFillColor(kYellow);
			mKPimPiPi->Draw("LEGO1 0");
			c1.SaveAs(outputSubDir + "mKPimPiPiLego.png");

			mKPimPiPi->Draw("SURF1");
			c1.SaveAs(outputSubDir + "mKPimPiPiSurf1.png");

			mKPimPiPi->Draw("SURF3");
			c1.SaveAs(outputSubDir + "mKPimPiPiSurf3.png");

			cosThetaAcosThetaCHist->Draw("COLZ");
			c1.SaveAs(outputSubDir + "cosThetaAcosThetaCHist.png");

			tAtCD02KstarRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD02KstarRho.png");

			tAtCD0bar2KstarRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD0bar2KstarRho.png");

			gStyle->SetOptStat("rme");

			quad1PhiHistD02KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD02KstarRho.png");

			quad2PhiHistD02KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD02KstarRho.png");

			quad3PhiHistD02KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD02KstarRho.png");

			quad4PhiHistD02KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD02KstarRho.png");

			quad1PhiHistD0bar2KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD0bar2KstarRho.png");

			quad2PhiHistD0bar2KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD0bar2KstarRho.png");

			quad3PhiHistD0bar2KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD0bar2KstarRho.png");

			quad4PhiHistD0bar2KstarRho->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD0bar2KstarRho.png");

			gStyle->SetOptStat(0);

			allPhiHistD02KstarF0->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD02KstarF0.png");

			allPhiHistD0bar2KstarF0->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD0bar2KstarF0.png");

			tAtCD02KstarF0->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD02KstarF0.png");

			tAtCD0bar2KstarF0->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD0bar2KstarF0.png");

			gStyle->SetOptStat("rme");

			quad1PhiHistD02KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD02KstarF0.png");

			quad2PhiHistD02KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD02KstarF0.png");

			quad3PhiHistD02KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD02KstarF0.png");

			quad4PhiHistD02KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD02KstarF0.png");

			quad1PhiHistD0bar2KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD0bar2KstarF0.png");

			quad2PhiHistD0bar2KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD0bar2KstarF0.png");

			quad3PhiHistD0bar2KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD0bar2KstarF0.png");

			quad4PhiHistD0bar2KstarF0->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD0bar2KstarF0.png");

			gStyle->SetOptStat(0);

			allPhiHistD02KappaRho->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD02KappaRho.png");

			allPhiHistD0bar2KappaRho->Draw();
			c1.SaveAs(outputSubDir + "allPhiHistD0bar2KappaRho.png");

			tAtCD02KappaRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD02KappaRho.png");

			tAtCD0bar2KappaRho->Draw("COLZ");
			c1.SaveAs(outputSubDir + "tAtCD0bar2KappaRho.png");

			gStyle->SetOptStat("rme");

			quad1PhiHistD02KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD02KappaRho.png");

			quad2PhiHistD02KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD02KappaRho.png");

			quad3PhiHistD02KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD02KappaRho.png");

			quad4PhiHistD02KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD02KappaRho.png");

			quad1PhiHistD0bar2KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad1PhiHistD0bar2KappaRho.png");

			quad2PhiHistD0bar2KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad2PhiHistD0bar2KappaRho.png");

			quad3PhiHistD0bar2KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad3PhiHistD0bar2KappaRho.png");

			quad4PhiHistD0bar2KappaRho->Draw();
			c1.SaveAs(outputSubDir + "quad4PhiHistD0bar2KappaRho.png");
		}
	}; // end class CommonHistsWithKinematics

} // end namespace K3PiStudies
