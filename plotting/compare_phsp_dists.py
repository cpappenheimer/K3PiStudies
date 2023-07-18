import ROOT
import numpy as np
import math
import sys

PY_UTILS_PKG_DIR = "/data/home/pappenheimer/develop_k3pistudies/K3PiStudies/extern/k3pi_utilities/python/src"

sys.path.append(PY_UTILS_PKG_DIR)   
import py_k3pi_utilities.utils

def main():
    ##### CONFIG
    DEBUG_MODE = False

    UTILS_BUILD_DIR = "/data/home/pappenheimer/develop_k3pistudies/build/extern/k3pi_utilities/"
    UTILS_INC_DIR = "/data/home/pappenheimer/develop_k3pistudies/K3PiStudies/extern/k3pi_utilities/include/"

    AMP_GEN_FILE = "/share/lazy/pappenheimer/d2k3pi/data/toy_MC_AmpGen_TD/D02Kpipipi_td_1000000events.root"
    GOOFIT_FILE = "/share/lazy/pappenheimer/d2k3pi/data/toy_MC_GooFit_tim_model/RS_D0_tim_model_toy_mc_signal_x0.0_y0.0_1000000events_sampleNum0_generationSeed3626764237.csv"
    #GOOFIT_FILE = "/share/lazy/pappenheimer/d2k3pi/data/toy_MC_GooFit_tim_model/test.txt"

    IS_D0 = True
    IS_RS = True
    INCLUDE_T = True

    OUT_DIR = "/share/lazy/pappenheimer/d2k3pi/plotting/test/"
    SAVE_EXT = ".png"

    AMP_GEN_TREE_NAME = "DalitzEventList"

    GOOFIT_T_COL_NAME = "t"
    GOOFIT_PHI_COL_NAME = "phi"
    GOOFIT_M12_COL_NAME = "m12"
    GOOFIT_M34_COL_NAME = "m34"

    AMP_GEN_D0_MASS_GEV = 1.86464 

    SINGLE_HIST_STAT_STYLE = "rmeuo" 
    #############

    ##### DO ANALYSIS
    if DEBUG_MODE:
        ROOT.DisableImplicitMT()
    else:
        ROOT.EnableImplicitMT(16)

    ROOT.gStyle.SetOptStat(SINGLE_HIST_STAT_STYLE)

    py_k3pi_utilities.utils.loadK3PiCUtils(UTILS_BUILD_DIR, UTILS_INC_DIR)

    HIST_NAMES = ["m12", "m34", "c12", "c34", "phi"]
    if INCLUDE_T:
        HIST_NAMES.append("t")

    M_UNIT = "GeV"
    COS_UNIT = ""
    PHI_UNIT = "rad"
    T_UNIT = "ns"
    HIST_UNITS = [M_UNIT, M_UNIT, COS_UNIT, COS_UNIT, PHI_UNIT]
    if INCLUDE_T:
        HIST_UNITS.append(T_UNIT)

    Y_TITLE_OFFSET = 1.45

    COS_THETA_AXIS_MIN = -1.0
    COS_THETA_AXIS_MAX = 1.0
    COS_THETA_N_BINS = 100
    COS_THETA_Y_LABEL = ROOT.K3PiStudies.K3PiStudiesUtils.makeYAxisLabel(COS_THETA_N_BINS,COS_THETA_AXIS_MIN,COS_THETA_AXIS_MAX,COS_UNIT,False)
    COS_THETA12_TITLE = ROOT.K3PiStudies.K3PiStudiesUtils.makeTitleStr('', 'cos #theta_{12}', COS_THETA_Y_LABEL)
    COS_THETA34_TITLE = ROOT.K3PiStudies.K3PiStudiesUtils.makeTitleStr('', 'cos #theta_{34}', COS_THETA_Y_LABEL)

    PHI_AXIS_MIN = 0.0
    PHI_AXIS_MAX = 2.0 * math.pi
    PHI_N_BINS = 100
    PHI_Y_LABEL = ROOT.K3PiStudies.K3PiStudiesUtils.makeYAxisLabel(PHI_N_BINS,PHI_AXIS_MIN,PHI_AXIS_MAX,PHI_UNIT,False)
    PHI_TITLE = ROOT.K3PiStudies.K3PiStudiesUtils.makeTitleStr('', '#phi', PHI_Y_LABEL)

    D0_TAU_PDG_NS = 0.0004103

    T_AXIS_MIN_NS = 0.0
    T_AXIS_MAX_NS = 11.0 * D0_TAU_PDG_NS
    T_N_BINS = 220
    T_Y_LABEL = ROOT.K3PiStudies.K3PiStudiesUtils.makeYAxisLabel(T_N_BINS,T_AXIS_MIN_NS,T_AXIS_MAX_NS,T_UNIT,False)
    T_TITLE = ROOT.K3PiStudies.K3PiStudiesUtils.makeTitleStr('', 't [ns]', T_Y_LABEL)

    AMP_GEN_LEG_TITLE = "AmpGen"
    GOOFIT_LEG_TITLE = "GooFit"

    # get goofit data
    gooFitDF = py_k3pi_utilities.utils.csvFileToDF(GOOFIT_FILE)
    # if DEBUG_MODE:
    #     print(gooFitDF.GetColumnNames())

    # get amp gen data
    ampGenDF = py_k3pi_utilities.utils.rootFileToDF(AMP_GEN_TREE_NAME, AMP_GEN_FILE)

    # alias col so don't have special chars in col names
    K_NAME = "K"
    OS_PI1_NAME = "OSPi1"
    OS_PI2_NAME = "OSPi2"
    SS_PI_NAME = "SSPi"
    ampGenDF = py_k3pi_utilities.utils.aliasAmpGen4VecComponents(ampGenDF, 1, py_k3pi_utilities.utils.getAmpGenKName, K_NAME, IS_D0, IS_RS)
    ampGenDF = py_k3pi_utilities.utils.aliasAmpGen4VecComponents(ampGenDF, 2, py_k3pi_utilities.utils.getAmpGenOSPiName, OS_PI1_NAME, IS_D0, IS_RS)
    ampGenDF = py_k3pi_utilities.utils.aliasAmpGen4VecComponents(ampGenDF, 3, py_k3pi_utilities.utils.getAmpGenOSPiName, OS_PI2_NAME, IS_D0, IS_RS)
    ampGenDF = py_k3pi_utilities.utils.aliasAmpGen4VecComponents(ampGenDF, 4, py_k3pi_utilities.utils.getAmpGenSSPiName, SS_PI_NAME, IS_D0, IS_RS)

    # calculate the phsp vars we use in GooFit
    k4VecCStr = "K3PiStudies::K3PiStudiesUtils::toTLorentzVector(_1_{0}_E, _1_{0}_Px, _1_{0}_Py, _1_{0}_Pz)".format(K_NAME)
    os1Pi4VecCStr = "K3PiStudies::K3PiStudiesUtils::toTLorentzVector(_2_{0}_E, _2_{0}_Px, _2_{0}_Py, _2_{0}_Pz)".format(OS_PI1_NAME)
    os2Pi4VecCStr = "K3PiStudies::K3PiStudiesUtils::toTLorentzVector(_3_{0}_E, _3_{0}_Px, _3_{0}_Py, _3_{0}_Pz)".format(OS_PI2_NAME)
    ssPi4VecCStr = "K3PiStudies::K3PiStudiesUtils::toTLorentzVector(_4_{0}_E, _4_{0}_Px, _4_{0}_Py, _4_{0}_Pz)".format(SS_PI_NAME)
    d04VecCStr = "K3PiStudies::K3PiStudiesUtils::toTLorentzVector({}, 0.0, 0.0, 0.0)".format(AMP_GEN_D0_MASS_GEV)
    phspFuncCStr = "K3PiStudies::K3PiStudiesUtils::calc_phsp("+d04VecCStr+","+k4VecCStr+","+os1Pi4VecCStr+","+ssPi4VecCStr+","+os2Pi4VecCStr+")"
    ampGenDF = ampGenDF.Define("phsp", phspFuncCStr)
    ampGenDF = ampGenDF.Define("m12", "phsp[0]")
    ampGenDF = ampGenDF.Define("m34", "phsp[1]")
    ampGenDF = ampGenDF.Define("c12", "phsp[2]")
    ampGenDF = ampGenDF.Define("c34", "phsp[3]")
    ampGenDF = ampGenDF.Define("phi", "phsp[4]")

    # t in GooFit data is in ps, need to convert to ns to match AmpGen
    gooFitDF = gooFitDF.Define("t_ns", GOOFIT_T_COL_NAME+" / 1000.0")

    # phi in GooFit data ranges from -pi to pi, need to convert to 0 to 2 pi to match AmpGen
    gooFitDF = gooFitDF.Define("phi_negPi_to_pi", 
                               "K3PiStudies::K3PiStudiesUtils::changeAngleRange_0_to_2pi("+GOOFIT_PHI_COL_NAME+")")
    
    # m12, m34 in GooFit data are in MeV, need to convert to GeV to match AmpGen
    gooFitDF = gooFitDF.Define("m12_GeV", GOOFIT_M12_COL_NAME+" / 1000.0")
    gooFitDF = gooFitDF.Define("m34_GeV", GOOFIT_M34_COL_NAME+" / 1000.0")

    # AmpGen hists
    ampGenM12Hist = py_k3pi_utilities.utils.loadHistFromFile(AMP_GEN_FILE, "s01")
    ampGenM34Hist = py_k3pi_utilities.utils.loadHistFromFile(AMP_GEN_FILE, "s23")
    ampGenC12Hist = py_k3pi_utilities.utils.createHistFromDF(
        ampGenDF, 
        "c12", 
        "c12_ampgen",
        COS_THETA12_TITLE, COS_THETA_N_BINS, COS_THETA_AXIS_MIN, COS_THETA_AXIS_MAX)
    ampGenC34Hist = py_k3pi_utilities.utils.createHistFromDF(
        ampGenDF, 
        "c34",
        "c34_ampgen", 
        COS_THETA34_TITLE, COS_THETA_N_BINS, COS_THETA_AXIS_MIN, COS_THETA_AXIS_MAX)
    ampGenPhiHist = py_k3pi_utilities.utils.createHistFromDF(
        ampGenDF,
        "phi", 
        "phi_ampgen", 
        PHI_TITLE, PHI_N_BINS, PHI_AXIS_MIN, PHI_AXIS_MAX)
    ampGenHists = [ampGenM12Hist, ampGenM34Hist, ampGenC12Hist, ampGenC34Hist, ampGenPhiHist]
    if INCLUDE_T:
        ampGenTHist = py_k3pi_utilities.utils.createHistFromDF(
            ampGenDF,
            "D0_decayTime", 
            "t_ampgen", 
            T_TITLE, T_N_BINS, T_AXIS_MIN_NS, T_AXIS_MAX_NS)
        ampGenHists.append(ampGenTHist)

    # GooFit hists
    gooFitM12Hist = py_k3pi_utilities.utils.createHistWithSameXRange(gooFitDF, ampGenM12Hist, "m12_GeV", "_goofit")
    gooFitM34Hist = py_k3pi_utilities.utils.createHistWithSameXRange(gooFitDF, ampGenM34Hist, "m34_GeV", "_goofit")
    gooFitC12Hist = py_k3pi_utilities.utils.createHistFromDF(
        gooFitDF,
        "c12",
        "c12_goofit",
        COS_THETA12_TITLE, COS_THETA_N_BINS, COS_THETA_AXIS_MIN, COS_THETA_AXIS_MAX)
    gooFitC34Hist = py_k3pi_utilities.utils.createHistFromDF(
        gooFitDF,
        "c34",
        "c34_goofit",
        COS_THETA34_TITLE, COS_THETA_N_BINS, COS_THETA_AXIS_MIN, COS_THETA_AXIS_MAX)
    gooFitPhiHist = py_k3pi_utilities.utils.createHistFromDF(
        gooFitDF,
        "phi_negPi_to_pi",
        "phi_goofit",
        PHI_TITLE, PHI_N_BINS, PHI_AXIS_MIN, PHI_AXIS_MAX)
    gooFitHists = [gooFitM12Hist, gooFitM34Hist, gooFitC12Hist, gooFitC34Hist, gooFitPhiHist]
    if INCLUDE_T:
        gooFitTHist = py_k3pi_utilities.utils.createHistFromDF(
            gooFitDF,
            "t_ns",
            "t_goofit",
            T_TITLE, T_N_BINS, T_AXIS_MIN_NS, T_AXIS_MAX_NS)
        gooFitHists.append(gooFitTHist)

    # draw hists
    for n, u, a, g in zip(HIST_NAMES, HIST_UNITS, ampGenHists, gooFitHists):
        a.GetYaxis().SetTitleOffset(Y_TITLE_OFFSET)
        g.GetYaxis().SetTitleOffset(Y_TITLE_OFFSET)

        a.SetMinimum(0.0)
        g.SetMinimum(0.0)

        a.SetStats(1)
        py_k3pi_utilities.utils.drawHist(
            a, 
            SINGLE_HIST_STAT_STYLE, 
            OUT_DIR+n+"_ampgen"+SAVE_EXT)
        g.SetStats(1)
        py_k3pi_utilities.utils.drawHist(
            g, 
            SINGLE_HIST_STAT_STYLE, 
            OUT_DIR+n+"_goofit"+SAVE_EXT)

        a.SetStats(0)
        g.SetStats(0)
        py_k3pi_utilities.utils.drawSuperimposed(
            a, 
            AMP_GEN_LEG_TITLE, 
            g, 
            GOOFIT_LEG_TITLE, 
            OUT_DIR+n+"_compare" + SAVE_EXT)
        
        ROOT.K3PiStudies.K3PiStudiesUtils.makeNormalizedComparisonPlot(
            a, 
            g, 
            AMP_GEN_LEG_TITLE, 
            GOOFIT_LEG_TITLE, 
            True, 
            OUT_DIR+n+"_normalized"+SAVE_EXT,
            u, 
            True)
    # end loop over hists  
# end main

if __name__ == "__main__":
    main()