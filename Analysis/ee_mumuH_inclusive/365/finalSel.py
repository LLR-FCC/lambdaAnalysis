#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_mumuH_inclusive/365/presel/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"

process_list=['wzp6_ee_mumuH_ecm365','p8_ee_ZZ_ecm365','p8_ee_WW_ecm365','wzp6_gaga_mumu_60_ecm365']

###Dictionnay of the list of cuts. The key is the name of the selection that will be added to the output file
cut_list = {
            "selAll":"true",
            "sel0":"zed_leptonic_m.size() == 1 && zed_leptonic_charge[0] == 0",
            "sel1":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_charge[0] == 0",
            "sel2":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_charge[0] == 0",
            "sel3":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 20 && zed_leptonic_pt[0] < 70 && zed_leptonic_charge[0] == 0",

            "sel5":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 70 && zed_leptonic_charge[0] == 0",
            "sel6":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 80 && zed_leptonic_charge[0] == 0",
            #"sel4":"zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 86 &&  zed_leptonic_m[0] < 96 && zed_leptonic_recoil_m[0] > 120 && zed_leptonic_recoil_m[0] < 140 && zed_leptonic_pt[0] > 20 && zed_leptonic_pt[0] < 70 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonic_charge[0] == 0"
            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    "mz":{"name":"zed_leptonic_m","title":"M_{ij} [GeV]","bin":125,"xmin":0,"xmax":250},
    "mz_zoom":{"name":"zed_leptonic_m","title":"M_{ij} [GeV]","bin":40,"xmin":80,"xmax":100},
    "leptonic_recoil_m":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":0,"xmax":200},
    "leptonic_recoil_m_zoom":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":80,"xmax":160},
    "leptonic_recoil_m_zoom1":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom2":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom3":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":400,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom4":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":800,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom5":{"name":"zed_leptonic_recoil_m","title":"M_{Rec} [GeV]","bin":2000,"xmin":120,"xmax":140},
    "leptonic_pt"           :{"name":"zed_leptonic_pt"      ,"title":"p_{Tij} [GeV]" ,"bin":120,"xmin":0, "xmax":200},
    #"MET_costheta":{"name":"missingET_costheta","title":"cos(#theta_{miss})","bin":200,"xmin":-1,"xmax":1}
}

###Number of CPUs to use
NUM_CPUS = 5

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS)