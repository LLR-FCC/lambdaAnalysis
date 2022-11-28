import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/public/MA/Analysis/240/ee_mumuH_ecm240/presel/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = "https://fcc-physics-events.web.cern.ch/fcc-physics-events/sharedFiles/FCCee_procDict_spring2021_IDEA.json"
process_list=['wzp6_ee_mumuH_ecm240', 'p8_ee_WW_ecm240', 'p8_ee_Zll_ecm240', 'p8_ee_ZZ_ecm240']

###Dictionnay of the list of cuts. The key is the name of the selection that will be added to the output file
cut_list = {"sel0":"zed_leptonic_m.size() == 1",
            "sel1":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96",
            "sel2":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140",
            "sel3":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 20 && zed_leptonic_pt[0] < 70"
            }

#"sel2":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 20 && zed_leptonic_pt[0] < 70"


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    "mz"                    :{"name":"zed_leptonic_m"       ,"title":"m_{Z} [GeV]"            ,"bin":125,"xmin":0 ,"xmax":250},
    "mz_zoom"               :{"name":"zed_leptonic_m"       ,"title":"m_{Z} [GeV]"            ,"bin":40 ,"xmin":80,"xmax":100},
    "leptonic_recoil_m"     :{"name":"zed_leptonic_recoil_m","title":"Z leptonic recoil [GeV]","bin":100,"xmin":0 ,"xmax":200},
    "leptonic_recoil_m_zoom":{"name":"zed_leptonic_recoil_m","title":"Z leptonic recoil [GeV]","bin":200,"xmin":120,"xmax":140},
    "leptonic_pt"           :{"name":"zed_leptonic_pt"      ,"title":"Z leptonic p_{T} [GeV]" ,"bin":100,"xmin":20, "xmax":70}
}

###Number of CPUs to use
NUM_CPUS = 2

###Produce TTrees
DO_TREE=True

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS, doTree=DO_TREE)