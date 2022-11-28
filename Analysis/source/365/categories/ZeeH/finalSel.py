#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/eos/user/n/niharrin/llr/presel/365/source/"
#baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/"


###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"

#process_list=['wzp6_ee_eeH_ecm365']
process_list=['p8_ee_ZH_ecm365']
#process_list=['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365', 'wzp6_ee_ee_Mee_30_150_ecm365', 'wzp6_ee_tautau_ecm365']

#muss mit wahr/falsch antworten; std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).
#mass.at(i) gibt masse von beiden Z's zurück
#myFilter betrachtet 2 Z mit masse zwischen 80 und 100
ROOT.gInterpreter.Declare("""
bool myFilter(ROOT::VecOps::RVec<float> mass) {
    if (mass.size()<2) return false;
    for (size_t i = 0; i < mass.size(); ++i) {
       if (mass.at(i)<80. || mass.at(i)>100.)
        return false;
}
    return true;
}
""")

###Dictionnay of the list of cuts. The key is the name of the selection that will be added to the output file
cut_list = {
            #For wzp6 sample
            #"sel_ZeeH":"n_eminus == 1 && n_eplus == 1 && mass_ee < 110 && (!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (TMath::Abs(zed_leptonicE_m[0] - 91.188) < 6) && zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && missingET_costheta.size() == 1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicE_charge[0] == 0",

            #"sel_ZeeH_test":"n_eminus == 1 && n_eplus == 1 && mass_ee < 110 && (!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (TMath::Abs(zed_leptonicE_m[0] - 91.188) < 6)",

            #For p8 (ZH) sample /haben viel weniger events, da wir nicht nur "nur" Z-> ee behalten, sondern auch diese mit ISR rausschmeissen
            "sel_ZeeH":"!(n_zedsub_e == 2 && (mass_Zee < 110)) && (!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (TMath::Abs(zed_leptonicE_m[0] - 91.188) < 6) && zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicE_charge[0] == 0",

            #For p8 (WW,ZZ) sample
            #"sel_ZeeH":"(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (TMath::Abs(zed_leptonicE_m[0] - 91.188) < 6) && zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicE_charge[0] == 0",


            #"sel0":"(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) &&zed_leptonicE_m.size() == 1 && zed_leptonicE_charge[0] == 0",
            
            
            #"sel1":"zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_charge[0] == 0",
            #"sel2":"zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && zed_leptonicE_charge[0] == 0",
            #"sel3":"zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && zed_leptonicE_pt[0] > 20 && zed_leptonicE_pt[0] < 70 && zed_leptonicE_charge[0] == 0",
            #"sel4":"zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 120 && zed_leptonicE_recoil_m[0] < 140 && zed_leptonicE_pt[0] > 20 && zed_leptonicE_pt[0] < 70 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicE_charge[0] == 0",
            #"sel5":"zed_leptonicE_m.size() == 1 && zed_leptonicE_m[0] > 86 &&  zed_leptonicE_m[0] < 96 && zed_leptonicE_recoil_m[0] > 122 && zed_leptonicE_recoil_m[0] < 135 && zed_leptonicE_pt[0] > 20 && zed_leptonicE_pt[0] < 70 && missingET_costheta.size() ==1 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98 && zed_leptonicE_charge[0] == 0",

            #"sel_OrthCheck":"((!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (TMath::Abs(zed_leptonicE_m[0] - 91.188) < 6)) && (!(!(selected_muons_pt.size() == 2) && selected_electrons_pt.size() == 2) && !(!(selected_electrons_pt.size() == 2) && selected_muons_pt.size() == 2) && (higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1) && !(((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && !((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))) || (((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !(zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))) || (!((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))) || (((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))) || (!((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1 && !((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))) || (!((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && !(zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1) && !(zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 1) && ((zed_hadronic_subjets_ctag[0] == 1 && zed_hadronic_subjets_ctag[1] == 0) || (zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 1))))) && !(TMath::Abs(higgs_hadronic_m[0] - 125.) > 30))",
            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    "mz":{"name":"zed_leptonicE_m","title":"M_{ij} [GeV]","bin":125,"xmin":0,"xmax":250},
    "mz_zoom":{"name":"zed_leptonicE_m","title":"M_{ij} [GeV]","bin":40,"xmin":80,"xmax":100},
    "leptonic_recoil_m":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":0,"xmax":200},
    "leptonic_recoil_m_zoom":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":80,"xmax":160},
    "leptonic_recoil_m_zoom1":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":100,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom2":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":200,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom3":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":400,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom4":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":800,"xmin":120,"xmax":140},
    "leptonic_recoil_m_zoom5":{"name":"zed_leptonicE_recoil_m","title":"M_{Rec} [GeV]","bin":2000,"xmin":120,"xmax":140},
    "leptonic_pt"           :{"name":"zed_leptonicE_pt"      ,"title":"p_{Tij} [GeV]" ,"bin":100,"xmin":20, "xmax":70},
    "MET_costheta":{"name":"missingET_costheta","title":"cos(#theta_{miss})","bin":200,"xmin":-1,"xmax":1}
}

###Number of CPUs to use
NUM_CPUS = 8

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS, doTree=True)
#myana.run(ncpu=NUM_CPUS)