import subprocess as sb


####### Use this script to run the K3PiStudies.cpp plotting code,
####### which looks at mass and angular distributions for either data/full MC or toy MC.
####### Running code over data/full MC generates additional plots showing more kinematics.
####### Running code over toy MC generates plots showing mass/angular distributions only.


def main():
    ##### set up sample set (MODIFY THIS SECTION PROCESS YOUR DESIRED DATASETS)
    # the path to the directory containing the K3Pi executable (don't include trailing /)
    runDir = "../build"

    # the path to the directory in which to create the output root files (don't include trailing /)
    outDir = "/share/lazy/pappenheimer/d2k3pi/plotting/angular_dist_plots"

    # list of the root files to process
    # RS
    filesToProcess = ["/share/lazy/pappenheimer/d2k3pi/data/selected_data_extended/2015/randomly_selected_RS_multiple_candidates.root", "/share/lazy/pappenheimer/d2k3pi/data/selected_data_extended/2015/selected_rs_single_candidates.root"]
    #filesToProcess = ["/share/lazy/pappenheimer/d2k3pi/data/selected_data_extended/2015/selected_rs_single_candidates.root"]
    #filesToProcess = ["/data/home/pappenheimer/d2k3pi_data/selected_data_extended/2015/selected_evts_with_multiple_candidates_2015_MagDown_RS.root"]

    # true if sample is toy MC; false otherwise
    isToyMC = False

    # true if want to look at the sample in bins of decay time; false otherwise
    # change bin edges by modifying the upperBinEdges vector in K3PiStudies.cpp
    processInDecayTimeBins = False

    # The type of data to proccess: either RS, WS, or BOTH (will skip events that are not of specified type)
    mode = "RS"

    # Set this to true if want to apply Mike's original cuts to data
    # If true, will apply cuts and generate additional plots showing effects of cuts
    applyMikeCuts = False

    # Set to true if the D0 decay time is given as ctau (in mm) instead of tau (in ns)
    usingCTau = False

    # Set to true if want to use LHCb style for plots
    useLHCbStyle = True

    # The variable type to use for the daughter momenta: either REFIT, D0_FIT, or P (the D0_P0_PX, ... vars) [not used for toy MC]
    varType = "REFIT"

    # Set to true to compare the values of the phase space variables in the ntuple to the ones we calculate here (only for D0_Fit vars)
    comparePhsp = False

    # Set to true to print info for the first event
    printSanityChecks = False

    # Set to true if want to check that our calculated angles between vectors match results of ROOT's .Angle method
    verifyAngles = False

    # The (m, deltaM) region in which to process data (applies m, deltaM cut): either ALL or SIGNAL
    region = "ALL"
    ##### done setting up sample sets 


    ##### process files
    # create comma separated list of files to process
    commaSepFileList = ",".join(filesToProcess)

    # generate run command
    runArgs = "-f " + commaSepFileList + " -o " + outDir + " -m " + mode + " -v " + varType + " -r " + region
    if isToyMC:
        runArgs += " --toyMC"
    if applyMikeCuts:
        runArgs += " --applyMikeCuts"
    if usingCTau:
        runArgs += " --usingCTau"
    if processInDecayTimeBins:
        runArgs += " --processInDecayTimeBins"
    if useLHCbStyle:
        runArgs += " --useLHCbStyle"
    if comparePhsp:
        runArgs += " --comparePhsp"
    if printSanityChecks:
        runArgs += " --printSanityChecks"
    if verifyAngles:
        runArgs += " --verifyAngles"
    
    runCmd = runDir + "/angular_dists/src/K3PiStudies" + " " + runArgs
    formattedRunCmd = runCmd.split()

    print ("Run command:")
    print(runCmd)
    #print(formattedRunCmd)

    try:
        # run and print output to screen
        output = sb.check_output(formattedRunCmd, sb.STDOUT).decode("utf-8")
        for l in output.splitlines():
            print(l)
    except sb.CalledProcessError as err:
        print("ERROR PROCESSING SAMPLE!\n")
        for l in err.output.decode("utf-8").splitlines():
            print(l)
    #### done processing files

# end main


if __name__== "__main__":
    main()