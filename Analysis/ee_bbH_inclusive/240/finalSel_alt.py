#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/presel/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"
#procDict = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/auxiliaryFiles/normalization1.json" #Crosssection is 1; damit wir cuts setzen können


process_list=['wzp6_ee_qqH_ecm240','p8_ee_Zqq_ecm240', 'p8_ee_WW_ecm240', 'p8_ee_ZZ_ecm240']
#process_list=['p8_ee_WW_ecm240']
#process_list=['wzp6_ee_qqH_ecm240', 'p8_ee_WW_ecm240']

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
cut_list = {#"sel0":"JET_btag[0] == 1"
            #"sel0":"jets_kt_m.size() > 0 && zed_hadronic_m.size() == 1 && zed_hadronic_m[0] > 80 &&  zed_hadronic_m[0] < 100 && jets_kt_btag.size() > 1 && selected_bjets_pt[0] > 20 && zed_hadronic_pt[0] > 60"
            #zed_hadronic_m.size() == 1 &&
            "sel0":"jetNo[0] == 0 || jetNo[0] > 0",
            "sel1":"jetNo[0] > 1",
            "sel2":"jetNo[0] > 1 && bjetNo[0] > 1",
            #"sel3":"jetNo[0] > 2 && bjetNo[0] > 1 && FinalClassifier_BDT > 0.25",
            #"sel4":"jetNo[0] > 2 && bjetNo[0] > 1 && FinalClassifier_DNN > 0.1",
            #"sel5":"jetNo[0] > 2 && bjetNo[0] > 1 && FinalClassifier_MLP > 0.1",
            #"sel6":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_pt[0] < 55 && zed_hadronic_m[0] > 45 && FinalClassifier_BDT > 0.35",
            
            
            #"sel6":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_pt[0] > 20",
            #"sel7":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_pt[0] > 20 && FinalClassifier_BDT > 0.25",
            
            #"sel8":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_subjets_ctag.size() > 1 && zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 0 && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 120 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && FinalClassifier_BDT > 0.25 && FinalClassifier_BDT < 0.6",
            #"sel9":"jetNo[0] > 2 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0 &&  zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && FinalClassifier_BDT > 0.25 && FinalClassifier_BDT < 0.6",
            #"sel10":"jetNo[0] > 2 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100  && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && FinalClassifier_BDT > 0.25 && FinalClassifier_BDT < 0.6",
            #"sel11":"jetNo[0] > 2 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && FinalClassifier_BDT > 0.25 && FinalClassifier_BDT < 0.6",
            

            "sel6":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_pt[0] > 20",
            #"sel7":"jetNo[0] > 2 && bjetNo[0] > 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && zed_hadronic_pt[0] > 20 && _FinalClassifier_BDTG > 0.25",
            "sel7":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_subjets_ctag.size() > 1 && zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 0 && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96",
            
            #"sel8":"jetNo[0] > 3 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_subjets_ctag.size() > 1 && zed_hadronic_subjets_ctag[0] == 0 && zed_hadronic_subjets_ctag[1] == 0 && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25 ",
            #"sel8t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_ctag_true.size() > 1 && zed_hadronic_subjets_ctag_true[0] == 0 && zed_hadronic_subjets_ctag_true[1] == 0 && zed_hadronic_subjets_ltag_true.size() > 1 && zed_hadronic_subjets_ltag_true[0] == 0 && zed_hadronic_subjets_ltag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel9":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0 &&  zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel9t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 0 &&  zed_hadronic_subjets_ltag_true.size() > 1 && zed_hadronic_subjets_ltag_true[0] == 0 && zed_hadronic_subjets_ltag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel10":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100  && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel10t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100  && zed_hadronic_subjets_ltag_true.size() > 1 && zed_hadronic_subjets_ltag_true[0] == 0 && zed_hadronic_subjets_ltag_true[1] == 0 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel11":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_subjets_ltag.size() > 1 && zed_hadronic_subjets_ltag[0] == 0 && zed_hadronic_subjets_ltag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel11t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_ltag_true.size() > 1 && zed_hadronic_subjets_ltag_true[0] == 0 && zed_hadronic_subjets_ltag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel13":"_FinalClassifier_BDT > 0.26",


            #"sel8":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25 ",
            #"sel8t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel9":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel9t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel10":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel10t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100  && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel11":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel11t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel13":"_FinalClassifier_BDT > 0.26",

            #"sel8":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25 ",
            #"sel8t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel9":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel9t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel10":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel10t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100  && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel11":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            #"sel11t":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            #"sel13":"_FinalClassifier_BDT > 0.26",

            "selZjj":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            "selZjjMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZbb":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            "selZbbMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjb":"zed_hadronic_subjets_btag.size() > 1 && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",
            "selZjbMC":"zed_hadronic_subjets_btag_true.size() > 1 && ((zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 0) || (zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZotherMC":"!(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0) && !(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZbbcombZbbMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjbcombZbbMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_btag.size() > 1 && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjjcombZbbMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZbbcombZjjMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjbcombZjjMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_btag.size() > 1 && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjjcombZjjMC":"zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0 && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZbbcombZotherMC":"!(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0) && !(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjbcombZotherMC":"!(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0) && !(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1) && zed_hadronic_subjets_btag.size() > 1 && ((zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 0) || (zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 1)) && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            "selZjjcombZotherMC":"!(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 0 && zed_hadronic_subjets_btag_true[1] == 0) && !(zed_hadronic_subjets_btag_true.size() > 1 && zed_hadronic_subjets_btag_true[0] == 1 && zed_hadronic_subjets_btag_true[1] == 1) && zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 0 && zed_hadronic_subjets_btag[1] == 0 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > 0.25",

            

            "selZbbFinal":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > -0.08",
            "selZbbFinal2":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > -0.08 && missingET_e[0] < 35",
            "selZbbFinal3":"zed_hadronic_subjets_btag.size() > 1 && zed_hadronic_subjets_btag[0] == 1 && zed_hadronic_subjets_btag[1] == 1 && zed_hadronic_recoil_m[0] > 100 && zed_hadronic_recoil_m[0] < 160 && zed_hadronic_m[0] > 86 && zed_hadronic_m[0] < 96 && _FinalClassifier_BDT > -0.08 && missingET_e[0] < 35 && missingET_costheta[0] > -0.98 && missingET_costheta[0] < 0.98",


            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    #"btag":{"name":"JET_btag", "title":"btag", "bin":2, "xmin":0, "xmax":3},
    #"ctag":{"name":"jets_kt_ctag", "title":"ctag", "bin":2, "xmin":0, "xmax":2},
    #"m_ij":{"name":"jets_kt_m", "title":"m_ij", "bin":100, "xmin":20, "xmax":180},
    #"pT_b":{"name":"selected_bjets_pt", "title":"pT_b", "bin":100, "xmin":20, "xmax":180},
    #"m_b":{"name":"selected_bjets_m", "title":"pT_b", "bin":100, "xmin":20, "xmax":180}
    "mz":{"name":"zed_hadronic_m","title":"m_{Z} [GeV]","bin":125,"xmin":0,"xmax":250},
    "m_rec":{"name":"zed_hadronic_recoil_m","title":"m_{rec} [GeV]","bin":70,"xmin":100,"xmax":160},
    #"mz_zoom":{"name":"zed_hadronic_m","title":"m_{Z} [GeV]","bin":20,"xmin":80,"xmax":100},
    #"z_pt":{"name":"zed_hadronic_pt","title":"pT_{Z} [GeV]", "bin":100, "xmin":60, "xmax":120},
    "ht":{"name":"selected_bjet_ht","title":"HT_{b} [GeV]", "bin":150, "xmin":0, "xmax":250},
    "htheta":{"name":"zed_hadronic_theta","title":"theta", "bin":100, "xmin":0, "xmax":4},
    "hrtheta":{"name":"zed_hadronic_recoil_theta","title":"theta", "bin":100, "xmin":0, "xmax":4},
    "pT1":{"name":"zed_hadronic_subjets_pt1","title":"p_{T1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "pT2":{"name":"zed_hadronic_subjets_pt2","title":"p_{T2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "E1":{"name":"zed_hadronic_subjets_E1","title":"E_{j1} [GeV]","bin":125,"xmin":0,"xmax":200},
    "E2":{"name":"zed_hadronic_subjets_E2","title":"E_{j2} [GeV]","bin":125,"xmin":0,"xmax":200},
    "Eta1":{"name":"zed_hadronic_subjets_Eta1","title":"Eta_{1}","bin":125,"xmin":-20,"xmax":20},
    "Eta2":{"name":"zed_hadronic_subjets_Eta2","title":"Eta_{2}","bin":125,"xmin":-20,"xmax":20},
    "pT_ij":{"name":"zed_hadronic_pt","title":"p_{Tij} [GeV]","bin":125,"xmin":0,"xmax":200},
    "M_ij":{"name":"zed_hadronic_m","title":"m_{ij} [GeV]","bin":125,"xmin":0,"xmax":200},
    "Acoll_ij":{"name":"zed_hadronic_subjets_acoll","title":"Acoll_{ij}","bin":125,"xmin":0,"xmax":4},
    "Jet_No":{"name":"jetNo","title":"N_{jets}","bin":125,"xmin":0,"xmax":15},
    "bJet_No":{"name":"bjetNo","title":"N_{bjets}","bin":125,"xmin":0,"xmax":15},
    "zed_bJet_No":{"name":"zed_hadronic_subjets_btag","title":"N_{Zbjets}","bin":125,"xmin":0,"xmax":15},
    "zed_cJet_No":{"name":"zed_hadronic_subjets_ctag","title":"N_{Zcjets}","bin":125,"xmin":0,"xmax":15},
    "zed_lJet_No":{"name":"zed_hadronic_subjets_ltag","title":"N_{Zljets}","bin":125,"xmin":0,"xmax":15},
    "MET":{"name":"missingET_e","title":"MET","bin":125,"xmin":0,"xmax":120},
    "MET_Angle":{"name":"missingET_costheta","title":"MET_Theta","bin":125,"xmin":-1,"xmax":1},
    #"FinalClassifier_BDT":{"name":"FinalClassifier_BDT","title":"BDT","bin":250,"xmin":0,"xmax":1.2},
    "FinalClassifier_BDT":{"name":"_FinalClassifier_BDT","title":"BDT","bin":250,"xmin":-3,"xmax":1.2},
    #"FinalClassifier_DNN":{"name":"FinalClassifier_DNN","title":"DNN","bin":250,"xmin":0,"xmax":1.2},
    #"FinalClassifier_MLP":{"name":"FinalClassifier_MLP","title":"MLP","bin":250,"xmin":0,"xmax":1.2}
}

###Number of CPUs to use
NUM_CPUS = 5

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS)