#python examples/FCCee/higgs/mH-recoil/mumu/finalSel.py 

from config.common_defaults import deffccdicts

import sys, os
import ROOT

###Input directory where the files produced at the pre-selection level are
baseDir  = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_eebb_exclusive/presel_10/"

###Link to the dictonary that contains all the cross section informations etc...
procDict = os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "FCCee_procDict_spring2021_IDEA.json"
#procDict = "/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/auxiliaryFiles/normalization1.json" #Crosssection is 1; damit wir cuts setzen knnen


#process_list=['wzp6_ee_eeH_ecm365']
#process_list=['p8_ee_ZH_ecm365']
process_list=['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365']


#muss mit wahr/falsch antworten; std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).
#mass.at(i) gibt masse von beiden Z's zuruck
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
            "sel0":"true",

            #For wzp sample // zed_leptonic_m.size() == 1 selektiert zwei OS electons im final state
            #"selVBF_noBDT_VetoM":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",



            #"selVBF_noBDT_VetoM1":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25",

            #"selVBF_noBDT_VetoM2":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100",

            #"selVBF_noBDT_VetoM3":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90",

            #"selVBF_noBDT_VetoM4":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100",

            #"selVBF_noBDT_VetoM5":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && bjetNo[0] > 0",



            #"selVBF_noBDT_NoVetoM":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20", #Brauchen wir no MET?

            

            #"selVBF_VetoM":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM1":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM2":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM3":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM4":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227",
            
            #"selVBF_VetoM5":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227 && bjetNo[0] > 0",

            #"selVBF_NoVetoM":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",



            #For p8 sample (ZH)
            #"selVBF_noBDT_VetoM":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",


            
            #"selVBF_noBDT_VetoM1":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25",

            #"selVBF_noBDT_VetoM2":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100",

            #"selVBF_noBDT_VetoM3":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90",

            #"selVBF_noBDT_VetoM4":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100",

            #"selVBF_noBDT_VetoM5":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && bjetNo[0] > 0",



            #"selVBF_noBDT_NoVetoM":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",

            #"selVBF_VetoM":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",



            #"selVBF_VetoM1":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM2":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM3":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM4":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227",

            #"selVBF_VetoM5":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227 && bjetNo[0] > 0",



            #"selVBF_NoVetoM":"zed_leptonic_m.size() == 1 && !(n_zedsub_e == 2 && (mass_Zee > 110)) && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",



            #For p8 samples (WW, ZZ)
            #"selVBF_noBDT_VetoM":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",


            
            #"selVBF_noBDT_VetoM1":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25",

            #"selVBF_noBDT_VetoM2":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100",

            #"selVBF_noBDT_VetoM3":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90",

            #"selVBF_noBDT_VetoM4":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100",

            #"selVBF_noBDT_VetoM5":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && bjetNo[0] > 0",



            #"selVBF_noBDT_NoVetoM":"zed_leptonic_m.size() == 1 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",

            "selVBF_VetoM":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",



            "selVBF_VetoM1":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && _FinalClassifier_BDT_bb > -0.2227",

            "selVBF_VetoM2":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && _FinalClassifier_BDT_bb > -0.2227",

            "selVBF_VetoM3":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && _FinalClassifier_BDT_bb > -0.2227",

            "selVBF_VetoM4":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227",

            "selVBF_VetoM5":"zed_leptonic_m.size() == 1 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && higgs_hadronic_subjets_acollPaPb[0] > 1.25 && jet_ht[0] > 100 && higgs_hadronic_m[0] > 90 && missingET_e[0] < 100 && _FinalClassifier_BDT_bb > -0.2227 && bjetNo[0] > 0",



            "selVBF_NoVetoM":"zed_leptonic_m.size() == 1 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20 && _FinalClassifier_BDT_bb > -0.2227",

            #"sel1":"n_eminus == 1 && n_eplus == 1 && mass_ee > 100", #Je grösser, desto unwahrscheinlicher für ZH event! Wir killen aber auch H->ZZ*->eeXX!!!
            #"sel2":"n_eminus == 1 && n_eplus == 1 && mass_ee > 110", #Das wird gewählt!
            #"sel3":"n_eminus == 1 && n_eplus == 1 && mass_ee > 120",
            #"sel4":"n_eminus == 1 && n_eplus == 1 && mass_ee > 150",

            #"sel3":"zed_leptonic_m.size() == 1",
            #"sel4":"zed_leptonic_m.size() > 1",
            #"sel5":"n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && zed_leptonic_m.size() == 1 && zed_leptonic_m[0] > 80", #Nur VBF im wzp6, zed_leptonic macht keinen sinn
            #"sel1":"n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && zed_leptonic_m.size() == 0",

            #"sel1":"!(n_zedsub_e == 2 && (mass_Zee > 110))", #Je grösser, desto unwahrscheinlicher für ZH event! Wir killen aber auch H->ZZ*->eeXX!!!
            #"sel2":"n_zedsub_e == 2 && mass_Zee > 110", 
            #"sel3":"!(n_zedsub_e == 2)",
            #"sel4":"n_zedsub_e == 2",
            #"sel5":"n_zeminus == 1 && n_zeplus == 1",
            
            #"sel1":"n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",
            #"sel2":"zed_leptonic_m.size() == 1 && n_eminus == 1 && n_eplus == 1 && mass_ee > 110 && NmatchedMuons != 2 && jetNo[0] > 2 && higgs_hadronic_subjets_btag.size() > 1 && higgs_hadronic_subjets_btag[0] == 1 && higgs_hadronic_subjets_btag[1] == 1 && higgs_hadronic_subjets_DeltaEta.size() > 0 && higgs_hadronic_subjets_DeltaEta[0] < 3 && jet_ht[0] > 20",

            

            }


###Dictionary for the ouput variable/hitograms. The key is the name of the variable in the output files. "name" is the name of the variable in the input file, "title" is the x-axis label of the histogram, "bin" the number of bins of the histogram, "xmin" the minimum x-axis value and "xmax" the maximum x-axis value.
variables = {
    #"btag":{"name":"JET_btag", "title":"btag", "bin":2, "xmin":0, "xmax":3},
    #"ctag":{"name":"jets_kt_ctag", "title":"ctag", "bin":2, "xmin":0, "xmax":2},
    #"m_ij":{"name":"jets_kt_m", "title":"m_ij", "bin":100, "xmin":20, "xmax":180},
    #"pT_b":{"name":"selected_bjets_pt", "title":"pT_b", "bin":100, "xmin":20, "xmax":180},
    #"m_b":{"name":"selected_bjets_m", "title":"pT_b", "bin":100, "xmin":20, "xmax":180}
    "m_rec":{"name":"higgs_hadronic_recoil_m","title":"m_{Rec} [GeV]","bin":60,"xmin":0,"xmax":300},
    #"mz_zoom":{"name":"higgs_hadronic_m","title":"m_{Z} [GeV]","bin":20,"xmin":80,"xmax":100},
    #"z_pt":{"name":"higgs_hadronic_pt","title":"pT_{Z} [GeV]", "bin":100, "xmin":60, "xmax":120},
    "jet_ht":{"name":"jet_ht","title":"HT_{i} [GeV]", "bin":150, "xmin":0, "xmax":250},
    "htheta":{"name":"higgs_hadronic_theta","title":"#theta_{ij}", "bin":100, "xmin":0, "xmax":4},
    "hrtheta":{"name":"higgs_hadronic_recoil_theta","title":"#theta_{Rec}", "bin":100, "xmin":0, "xmax":4},
    "pT1":{"name":"higgs_hadronic_subjets_pt1","title":"p_{T1} [GeV]","bin":60,"xmin":0,"xmax":200},
    "pT2":{"name":"higgs_hadronic_subjets_pt2","title":"p_{T2} [GeV]","bin":60,"xmin":0,"xmax":200},
    "pL1":{"name":"higgs_hadronic_subjets_pl1","title":"p_{L1} [GeV]","bin":60,"xmin":-200,"xmax":200},
    "pL2":{"name":"higgs_hadronic_subjets_pl2","title":"p_{L2} [GeV]","bin":60,"xmin":-200,"xmax":200},
    "E1":{"name":"higgs_hadronic_subjets_E1","title":"E_{j1} [GeV]","bin":60,"xmin":0,"xmax":200},
    "E2":{"name":"higgs_hadronic_subjets_E2","title":"E_{j2} [GeV]","bin":60,"xmin":0,"xmax":200},
    "Eta1":{"name":"higgs_hadronic_subjets_Eta1","title":"Eta_{1}","bin":60,"xmin":-20,"xmax":20},
    "Eta2":{"name":"higgs_hadronic_subjets_Eta2","title":"Eta_{2}","bin":60,"xmin":-20,"xmax":20},
    "pT_ij":{"name":"higgs_hadronic_pt","title":"p_{Tij} [GeV]","bin":60,"xmin":0,"xmax":200},
    "pT_Rec":{"name":"higgs_hadronic_recoil_pt","title":"p_{TRec} [GeV]","bin":60,"xmin":0,"xmax":200},
    "pL_ij":{"name":"higgs_hadronic_pl","title":"p_{Lij} [GeV]","bin":60,"xmin":0,"xmax":200},
    "M_ij":{"name":"higgs_hadronic_m","title":"M_{ij} [GeV]","bin":60,"xmin":0,"xmax":200},
    "Acoll_ij":{"name":"higgs_hadronic_subjets_acoll","title":"Acoll_{ij}","bin":60,"xmin":-4,"xmax":4},
    "Acoll_PaPb":{"name":"higgs_hadronic_subjets_acollPaPb","title":"Acoll_{ij}","bin":60,"xmin":0,"xmax":4},
    "Jet_No":{"name":"jetNo","title":"N_{jets}","bin":60,"xmin":0,"xmax":15},
    "bJet_No":{"name":"bjetNo","title":"N_{bjets}","bin":60,"xmin":0,"xmax":10},
    "cJet_No":{"name":"cjetNo","title":"N_{cjets}","bin":60,"xmin":0,"xmax":10},
    "higgs_bJet_No":{"name":"higgs_hadronic_subjets_btag","title":"N_{Zbjets}","bin":60,"xmin":0,"xmax":15},
    "higgs_cJet_No":{"name":"higgs_hadronic_subjets_ctag","title":"N_{Zcjets}","bin":60,"xmin":0,"xmax":15},
    "higgs_lJet_No":{"name":"higgs_hadronic_subjets_ltag","title":"N_{Zljets}","bin":60,"xmin":0,"xmax":15},
    "MET":{"name":"missingET_e","title":"MET [GeV]","bin":60,"xmin":0,"xmax":200},
    "MET_Angle":{"name":"missingET_costheta","title":"cos(#theta_{Miss})","bin":60,"xmin":-1,"xmax":1},
    "pL_ij":{"name":"higgs_hadronic_pl","title":"p_{Lij} [GeV]","bin":60,"xmin":-200,"xmax":200},
    "pL_Rec":{"name":"higgs_hadronic_recoil_pl","title":"p_{LRec} [GeV]","bin":60,"xmin":0,"xmax":200},
    "DeltaEta_ij":{"name":"higgs_hadronic_subjets_DeltaEta","title":"#Delta #Eta_{ij}","bin":60,"xmin":0,"xmax":10},
    #"NNue":{"name":"number_of_nues","title":"N_{#nu_e}","bin":10,"xmin":0,"xmax":9},
    #"NNumu":{"name":"number_of_numus","title":"N_{#nu_#mu}","bin":10,"xmin":0,"xmax":9},
    #"NNutau":{"name":"number_of_nutaus","title":"N_{#nu_#tau}","bin":10,"xmin":0,"xmax":9},
    "MCM_ee":{"name":"mass_ee","title":"M_{ee} [GeV]","bin":60,"xmin":0,"xmax":350},
    "MCM_Zee":{"name":"mass_Zee","title":"M_{ee} [GeV]","bin":125,"xmin":0,"xmax":350},
    "n_zeplus":{"name":"n_zeplus","title":"N_{E}","bin":10,"xmin":0,"xmax":9},
    "n_zeminus":{"name":"n_zeminus","title":"N_{E}","bin":10,"xmin":0,"xmax":9},
    "n_zedsub_e":{"name":"n_zedsub_e","title":"N_{E}","bin":10,"xmin":0,"xmax":9},
    "M_ee":{"name":"zed_leptonic_m","title":"M_{ee} [GeV]","bin":60,"xmin":0,"xmax":350},
    "pT_ee":{"name":"zed_leptonic_pt","title":"pT_{ee} [GeV]","bin":60,"xmin":0,"xmax":350},
    #"ne_corrected":{"name":"ne_corrected","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":90},
    #"ne_corrected2":{"name":"ne_corrected2","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9},
    #"ne_corrected2":{"name":"ne_corrected2","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9},
    #"ne_corrected4":{"name":"ne_corrected4","title":"N_{#nu_#tau}","bin":100,"xmin":0,"xmax":9}
    #"FinalClassifier_BDT":{"name":"FinalClassifier_BDT","title":"BDT","bin":250,"xmin":0,"xmax":1.2},
    #"FinalClassifier_BDT_bb":{"name":"_FinalClassifier_BDT_bb","title":"#beta_{bb}","bin":250,"xmin":-3,"xmax":1.2},
    #"FinalClassifier_BDT_jb":{"name":"_FinalClassifier_BDT_jb","title":"#beta_{jb}","bin":250,"xmin":-3,"xmax":1.2},
    #"FinalClassifier_BDT_jj":{"name":"_FinalClassifier_BDT_jj","title":"#beta_{jj}","bin":250,"xmin":-3,"xmax":1.2},
    #"FinalClassifier_BDT_cc":{"name":"_FinalClassifier_BDT_cc","title":"#beta_{cc}","bin":250,"xmin":-3,"xmax":1.2}
    #"FinalClassifier_DNN":{"name":"FinalClassifier_DNN","title":"DNN","bin":250,"xmin":0,"xmax":1.2},
    #"FinalClassifier_MLP":{"name":"FinalClassifier_MLP","title":"MLP","bin":250,"xmin":0,"xmax":1.2}
}

###Number of CPUs to use
NUM_CPUS = 5

###This part is standard to all analyses
import config.runDataFrameFinal as rdf
myana=rdf.runDataFrameFinal(baseDir,procDict,process_list,cut_list,variables)
myana.run(ncpu=NUM_CPUS)
print(procDict)
