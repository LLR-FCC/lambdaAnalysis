#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
#baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/"
baseDir  = "/eos/user/n/niharrin/llr/presel/240/llH/source/"


###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"

#process_list=['wzp6_ee_mumuH_ecm240','p8_ee_ZZ_ecm240','p8_ee_WW_ecm240','p8_ee_Zll_ecm240', 'wzp6_gaga_mumu_60_ecm240']
#process_list=['p8_ee_WW_ecm240','p8_ee_Zll_ecm240', 'wzp6_gaga_mumu_60_ecm240']
process_list=['wzp6_ee_ee_Mee_30_150_ecm240']

###Dictionnay of the list of cuts. The key is the name of the selection that will be added to the output file
cut_list = {
            #"selAll":"true",
            #"sel0":"(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2)",
            #"sel1":"!(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2)",
            
            
            #"sel_ZmumuH":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_leptonicM_m.size() == 1 && zed_leptonicM_charge[0] == 0",
            #"sel_ZmumuH1":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_leptonicM_m.size() == 1 && zed_leptonicM_m[0] > 86 &&  zed_leptonicM_m[0] < 96 && zed_leptonicM_charge[0] == 0",
            #"sel_ZmumuH2":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_leptonicM_m.size() == 1 && zed_leptonicM_m[0] > 86 &&  zed_leptonicM_m[0] < 96 && zed_leptonicM_recoil_m[0] > 120 && zed_leptonicM_recoil_m[0] < 140 && zed_leptonicM_charge[0] == 0",
            #"sel_ZmumuH3":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_leptonicM_m.size() == 1 && zed_leptonicM_m[0] > 86 &&  zed_leptonicM_m[0] < 96 && zed_leptonicM_recoil_m[0] > 120 && zed_leptonicM_recoil_m[0] < 140 && zed_leptonicM_pt[0] > 20 && zed_leptonicM_pt[0] < 70 && zed_leptonicM_charge[0] == 0",

            "sel_ZmumuH4":"!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && zed_leptonicM_m.size() == 1 && zed_leptonicM_m[0] > 86 &&  zed_leptonicM_m[0] < 96 && zed_leptonicM_recoil_m[0] > 120 && zed_leptonicM_recoil_m[0] < 140 && zed_leptonicM_pt[0] > 20 && zed_leptonicM_pt[0] < 70 && zed_leptonicM_charge[0] == 0 && missingET_costheta.size() == 1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98",

            #"sel4":"zed_leptonicM_m.size() == 1 && zed_leptonicM_m[0] > 86 &&  zed_leptonicM_m[0] < 96 && zed_leptonicM_recoil_m[0] > 120 && zed_leptonicM_recoil_m[0] < 140 && zed_leptonicM_pt[0] > 20 && zed_leptonicM_pt[0] < 70 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicM_charge[0] == 0"

            #"sel_OrthCheck":"(!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && (!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2)) && (!(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2))",
            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    "mz":{"name":"zed_leptonicM_m","title":"M_{ij} [GeV]","bin":125,"xmin":0,"xmax":250},
    "mz_zoom":{"name":"zed_leptonicM_m","title":"M_{ij} [GeV]","bin":40,"xmin":80,"xmax":100},
    "leptonic_recoil_m":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":0,"xmax":200},
    "leptonic_recoil_m_zoom":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":80,"xmax":160},
    "leptonic_recoil_m_zoom1":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom2":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom3":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":400,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom4":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":800,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom5":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":2000,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom6":{"name":"zed_leptonicM_recoil_m","title":"M_{Rec} [GeV]","bin":70,"xmin":120,"xmax":140},
    "leptonic_pt"           :{"name":"zed_leptonicM_pt"      ,"title":"p_{Tij} [GeV]" ,"bin":120,"xmin":0, "xmax":200},
    "MET_costheta":{"name":"missingET_costheta","title":"cos(#theta_{miss})","bin":200,"xmin":-1,"xmax":1}
}

###Number of CPUs to use
NUM_CPUS = 8

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS, doTree=True)