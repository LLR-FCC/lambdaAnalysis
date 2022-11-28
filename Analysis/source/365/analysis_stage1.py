#Mandatory: List of processes
processList = {
    #'p8_ee_ZZ_ecm240':{},#Run the full statistics in one output file named <outputDir>/p8_ee_ZZ_ecm240.root
    #'p8_ee_WW_ecm240':{'fraction':0.5, 'chunks':2}, #Run 50% of the statistics in two files named <outputDir>/p8_ee_WW_ecm240/chunk<N>.root
    #'p8_ee_ZH_ecm240':{'fraction':0.2, 'output':'p8_ee_ZH_ecm240_out'} #Run 20% of the statistics in one file named <outputDir>/p8_ee_ZH_ecm240_out.root (example on how to change the output name)
    #'wzp6_ee_eeH_ecm365':{'fraction':1.0},
    #'wzp6_ee_mumuH_ecm365':{'fraction':1.0},
    #'wzp6_ee_qqH_ecm365':{'fraction':1.0},
    #'wzp6_ee_nunuH_ecm365':{'fraction':1.0},
    #'p8_ee_WW_ecm365':{'fraction':1.0},
    #'p8_ee_ZZ_ecm365':{'fraction':1.0},
    #'p8_ee_Zqq_ecm365':{'fraction':1.0},
    #'p8_ee_ZH_ecm365':{'fraction':1.0},
    #'wzp6_gaga_mumu_60_ecm365':{'fraction':1.0},
    #'wzp6_ee_ee_Mee_30_150_ecm365':{'fraction':1.0},
    #'wzp6_ee_mumu_ecm365':{'fraction':1.0},
    'wzp6_ee_tautau_ecm365':{'fraction':1.0}  
}

#Mandatory: Production tag when running over EDM4Hep centrally produced events, this points to the yaml files for getting sample statistics
prodTag     = "FCCee/spring2021/IDEA/"

#Optional: output directory, default is local running directory
outputDir   = "/eos/user/n/niharrin/llr/presel/365/source/"

#Optional: ncpus, default is 4
nCPUS       = 8

#Optional running on HTCondor, default is False
runBatch    = False

#Optional batch queue name when running on HTCondor, default is workday
batchQueue = "longlunch"

#Optional computing account when running on HTCondor, default is group_u_FCC.local_gen
compGroup = "group_u_CMS.u_zh.users"

#Optional test file
#testFile ="root://eospublic.cern.ch//eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/p8_ee_ZH_ecm240/events_101027117.root"

#Mandatory: RDFanalysis class where the use defines the operations on the TTree
class RDFanalysis():

    #__________________________________________________________
    #Mandatory: analysers funtion to define the analysers to process, please make sure you return the last dataframe, in this example it is df2
    def analysers(df):
        df2 = (
            df
            #.Alias("Jet3","Jet#3.index") 
               .Alias("MCRecoAssociations0", "MCRecoAssociations#0.index")
               .Alias("MCRecoAssociations1", "MCRecoAssociations#1.index")
               #.Alias("MCParents", "Particle#0.index")
               #.Alias("MCDaughters", "Particle#1.index")
               .Define("matchedMuons",       "ReconstructedParticle2MC::selRP_PDG(13, true)(MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle)")
               .Define("matchedElectrons",       "ReconstructedParticle2MC::selRP_PDG(11, true)(MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle)")
               .Define("NmatchedMuons",         "ReconstructedParticle::get_n(matchedMuons)")
               .Define("NmatchedElectrons",         "ReconstructedParticle::get_n(matchedElectrons)")
               
               .Alias("Particle0", "Particle#0.index")
               .Define("status2",           "FCCAnalyses::MCParticle::sel_genStatus(2)(Particle)")
               .Define("subprocess_nue",    "FCCAnalyses::MCParticle::sel_pdgID(12, true)(status2)")
               .Define("subprocess_numu",    "FCCAnalyses::MCParticle::sel_pdgID(14, true)(status2)")
               .Define("subprocess_nutau",    "FCCAnalyses::MCParticle::sel_pdgID(16, true)(status2)")
               .Define("subprocess_zed",    "FCCAnalyses::MCParticle::sel_pdgID(23, true)(status2)")
               .Define("number_of_nues",    "return subprocess_nue.size();")
               .Define("number_of_numus",    "return subprocess_numu.size();")
               .Define("number_of_nutaus",    "return subprocess_nutau.size();")
               .Define("number_of_zeds",    "return subprocess_zed.size();")

               .Define("status1",           "FCCAnalyses::MCParticle::sel_genStatus(1)(Particle)")
               .Define("subprocess_nuef",    "FCCAnalyses::MCParticle::sel_pdgID(12, true)(status1)")
               .Define("subprocess_numuf",    "FCCAnalyses::MCParticle::sel_pdgID(14, true)(status1)")
               .Define("subprocess_nutauf",    "FCCAnalyses::MCParticle::sel_pdgID(16, true)(status1)")
               .Define("number_of_nuesf",    "return subprocess_nuef.size();")
               .Define("number_of_numusf",    "return subprocess_numuf.size();")
               .Define("number_of_nutausf",    "return subprocess_nutauf.size();")

               .Define("ZEvts", "FCCAnalyses::MCParticle::filter_pdgID(23, true)(Particle)")
               .Define("WEvts", "FCCAnalyses::MCParticle::filter_pdgID(24, true)(Particle)")
               .Define("NuMEvts", "FCCAnalyses::MCParticle::filter_pdgID(14, true)(Particle)")
               .Define("NuTEvts", "FCCAnalyses::MCParticle::filter_pdgID(16, true)(Particle)")

               .Define("nue_origin",  "LLRHiggsTools::get_leptons_origin( subprocess_nue, Particle, Particle0 )")
               .Define("ne_corrected",  " return int( std::count(nue_origin.begin(), nue_origin.end(), -11) ) ; ") #.begin() = start der 'liste'; .end() = ende der 'liste'; suche nach -11
               #.Define("ne_corrected2", " return int( std::count(nue_origin.begin(), nue_origin.end(), 11)  )  ; ")
               #.Define("ne_corrected3", " return int( std::count(nue_origin.begin(), nue_origin.end(), 0)  )  ; ")
               #.Define("ne_corrected4", " return int( std::count(nue_origin.begin(), nue_origin.end(), 23)  )  ; ")
               
               #.Define("ZNuENuEIndex",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {12, 12}, true, true)(Particle, MCDaughters)")
               #.Define("ZNuMuNuMuIndex",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {14, 14}, true, true)(Particle, MCDaughters)")
               #.Define("ZNuTauNuTauIndex",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {16, 16}, true, true)(Particle, MCDaughters)")
               #.Define("ZNuENuEIndex2",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {12, -12}, true, false)(Particle, MCDaughters)")
               #.Define("ZNuMuNuMuIndex2",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {14, -14}, true, false)(Particle, MCDaughters)")
               #.Define("ZNuTauNuTauIndex2",        "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {16, -16}, true, false)(Particle, MCDaughters)")
               #.Define("NuMu1", "LLRHiggsTools::selMC_leg(0)(ZNuMuNuMuIndex2, Particle)")
               #.Define("NuMu2", "LLRHiggsTools::selMC_leg(1)(ZNuMuNuMuIndex2, Particle)")
               #.Define("NuTau1", "LLRHiggsTools::selMC_leg(0)(ZNuTauNuTauIndex2, Particle)")
               #.Define("NuTau2", "LLRHiggsTools::selMC_leg(1)(ZNuTauNuTauIndex2, Particle)")               
               #.Define("ZMu", "FCCAnalyses::MCParticle::mergeParticles(NuMu1, NuMu2)")
               #.Define("ZTau", "FCCAnalyses::MCParticle::mergeParticles(NuTau1, NuTau2)")
               #.Define("NZMu", "FCCAnalyses::MCParticle::get_n(ZMu)")
               #.Define("NZTau", "FCCAnalyses::MCParticle::get_n(ZTau)")

               #.Define("ZHZIndex", "FCCAnalyses::MCParticle::get_indices_ExclusiveDecay(23, {23, 25}, false, false)(Particle, MCDaughters)")
               #.Define("ZHZ", "LLRHiggsTools::selMC_leg(0)(ZHZIndex, Particle)")
               #.Define("NZHZ", "FCCAnalyses::MCParticle::get_n(ZHZ)")

               #.Define("ZNuMuNuMu",             "FCCAnalyses::MCParticle::get_decay(23, 14, false)(Particle, MCParents)")
               #.Define("ZNuTauNuTau",             "FCCAnalyses::MCParticle::get_decay(23, 16, false)(Particle, MCParents)")
               #.Define("ZNuENuE",             "FCCAnalyses::MCParticle::get_decay(23, 12, false)(Particle, MCParents)")
               
               #.Define("ZNuENuE2",             "FCCAnalyses::MCParticle::get_decay(23, 12, false)(Particle, MCDaughters)")
               #.Define("ZNuMuNuMu2",             "FCCAnalyses::MCParticle::get_decay(23, 14, false)(Particle, MCDaughters)")
               #.Define("ZNuTauNuTau2",             "FCCAnalyses::MCParticle::get_decay(23, 16, false)(Particle, MCDaughters)")
               

               #define the RP px, py, pz and e
               .Define("RP_px",         "ReconstructedParticle::get_px(ReconstructedParticles)")
               .Define("RP_py",         "ReconstructedParticle::get_py(ReconstructedParticles)")
               .Define("RP_pz",         "ReconstructedParticle::get_pz(ReconstructedParticles)")
               .Define("RP_e",         "ReconstructedParticle::get_e(ReconstructedParticles)")
               .Define("RP_m",         "ReconstructedParticle::get_mass(ReconstructedParticles)")
               .Define("RP_q",         "ReconstructedParticle::get_charge(ReconstructedParticles)")
               #Build pseudojets 
               .Define("pseudo_jets",   "JetClusteringUtils::set_pseudoJets_xyzm(RP_px, RP_py, RP_pz, RP_m)")

               
               .Define("FCCAnalysesJets_kt", "JetClustering::clustering_ee_genkt(0.5, 0, 5., 0, 0, -1)(pseudo_jets)")
               #extract the jets out of the struct (the thing above), Das Objekt selbst (der Jet als Teilchen)
               .Define("jets_kt",   "JetClusteringUtils::get_pseudoJets(FCCAnalysesJets_kt)")
               #get the jets constituents out of the struct, Inhalt des Cones
               .Define("jetconstituents_kt","JetClusteringUtils::get_constituents(FCCAnalysesJets_kt)")
               #Get variables
               .Define("jets_kt_pt",    "JetClusteringUtils::get_pt(jets_kt)")
               #.Define("jets_kt_pt1",    "JetClusteringUtils::get_pt(jetconstituents_kt[0])")
               #.Define("jets_kt_pt2",    "JetClusteringUtils::get_pt(jetconstituents_kt[1])")
               .Define("jets_kt_m",    "JetClusteringUtils::get_m(jets_kt)")
               #.Define("jets_kt_px",    "JetClusteringUtils::get_px(jets_kt)")
               #.Define("jets_kt_py",    "JetClusteringUtils::get_py(jets_kt)")
               #.Define("jets_kt_pz",    "JetClusteringUtils::get_pz(jets_kt)")
               .Define("jets_kt_flavor","JetTaggingUtils::get_flavour(jets_kt, Particle)")
               .Define("jets_kt_btag",    "JetTaggingUtils::get_btag(jets_kt_flavor, 0.80, 0.08, 0.01, 0.01)") #80% Tagging-Effizienz
               .Define("jets_kt_btag_ideal",    "JetTaggingUtils::get_btag(jets_kt_flavor, 1.0)") #100% Tagging-Effizienz (Idealfall)
               .Define("jets_kt_ctag",    "JetTaggingUtils::get_ctag(jets_kt_flavor, 0.60, 0.10, 0.01, 0.03)") #60% Tagging-Effizienz
               .Define("jets_kt_ctag_ideal",    "JetTaggingUtils::get_ctag(jets_kt_flavor, 1.0)") #100% Tagging-Effizienz (Idealfall)
               
               #.Define("jets_kt_comb",  "JetClusteringUtils::get_compositeJets(jets_kt)")

               .Define("selected_bjets",    "JetTaggingUtils::sel_tag(1)(jets_kt_btag, jets_kt)")
               .Define("selected_cjets",    "JetTaggingUtils::sel_tag(1)(jets_kt_ctag, jets_kt)")

               .Define("selected_bjets_pt", "JetClusteringUtils::get_pt(selected_bjets)") #müssen jets noch recombinen
               .Define("selected_bjets_m", "JetClusteringUtils::get_m(selected_bjets)")

               .Define("selected_bjet_ht",  "LLRHiggsTools::get_ht(selected_bjets)")

               #.Define("selected_jets", "ReconstructedParticle::sel_pt(60.)(Jet)")
               # create branch with electron rapidity
               #.Define("selected_electrons_y",  "ReconstructedParticle::get_y(selected_electrons)") 
               # create branch with electron total momentum
               #.Define("selected_electrons_p",     "ReconstructedParticle::get_p(selected_electrons)")
               # create branch with electron energy 
               #.Define("selected_electrons_e",     "ReconstructedParticle::get_e(selected_electrons)")
               
               # find higgs candidates from  di-jet resonances  
               .Define("higgs_hadronic",         "LLRHiggsTools::jetResonanceBuilder(125.10)(jets_kt)")
               .Define("higgs_hadronic_subjets", "LLRHiggsTools::get_compositeSubJets(higgs_hadronic)")
               .Define("higgs_hadronic_subjets_pt1",  "LLRHiggsTools::get_subjetpt(0, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_pt2",  "LLRHiggsTools::get_subjetpt(1, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_pl1",  "LLRHiggsTools::get_subjetpl(0, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_pl2",  "LLRHiggsTools::get_subjetpl(1, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_E1",   "LLRHiggsTools::get_subjetE(0, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_E2",   "LLRHiggsTools::get_subjetE(1, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_Eta1", "LLRHiggsTools::get_subjetEta(0, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_Eta2", "LLRHiggsTools::get_subjetEta(1, higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_theta",  "JetClusteringUtils::get_theta(higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_acoll",  "LLRHiggsTools::get_subjetAcoll(higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_acollPaPb",  "LLRHiggsTools::get_subjetAcollPaPb(higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_DeltaPhi",  "LLRHiggsTools::get_subjetDeltaPhi(higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_DeltaEta",  "LLRHiggsTools::get_subjetDeltaEta(higgs_hadronic_subjets)")
               .Define("higgs_hadronic_subjets_flavor",  "JetTaggingUtils::get_flavour(higgs_hadronic_subjets, Particle)")
               .Define("higgs_hadronic_subjets_btag",    "JetTaggingUtils::get_btag(higgs_hadronic_subjets_flavor, 0.80, 0.08, 0.01, 0.01)")
               .Define("higgs_hadronic_subjets_ctag",    "JetTaggingUtils::get_ctag(higgs_hadronic_subjets_flavor, 0.60, 0.10, 0.01, 0.03)")
               .Define("higgs_hadronic_subjets_ltag",    "JetTaggingUtils::get_ltag(higgs_hadronic_subjets_flavor, 0.80)")
               .Define("higgs_hadronic_subjets_btag_true",    "JetTaggingUtils::get_btag(higgs_hadronic_subjets_flavor, 1.0)")
               .Define("higgs_hadronic_subjets_ctag_true",    "JetTaggingUtils::get_ctag(higgs_hadronic_subjets_flavor, 1.0)")
               .Define("higgs_hadronic_subjets_ltag_true",    "JetTaggingUtils::get_ltag(higgs_hadronic_subjets_flavor, 1.0)")
               .Define("jetNo",  "LLRHiggsTools::get_jetNo(jets_kt)")
               .Define("bjetNo",  "LLRHiggsTools::get_jetNo(selected_bjets)")
               .Define("cjetNo",  "LLRHiggsTools::get_jetNo(selected_cjets)")
               .Define("jet_ht",  "LLRHiggsTools::get_ht(jets_kt)")
               # write branch with higgs mass
               .Define("higgs_hadronic_m",       "JetClusteringUtils::get_m(higgs_hadronic)")
               .Define("higgs_hadronic_pt",       "JetClusteringUtils::get_pt(higgs_hadronic)")
               .Define("higgs_hadronic_pl",       "JetClusteringUtils::get_pz(higgs_hadronic)")
               # write branch with zed transverse momenta
               #.Define("zed_hadronic_pt",      "ReconstructedParticle::get_pt(zed_hadronic)")
               # calculate recoil of higgs_hadronic
               .Define("higgs_hadronic_recoil",  "LLRHiggsTools::jetRecoilBuilder(365.)(higgs_hadronic)")
               # write branch with recoil mass
               .Define("higgs_hadronic_recoil_m","JetClusteringUtils::get_m(higgs_hadronic_recoil)")
               .Define("higgs_hadronic_recoil_pt","JetClusteringUtils::get_pt(higgs_hadronic_recoil)")
               .Define("higgs_hadronic_recoil_pl","JetClusteringUtils::get_pz(higgs_hadronic_recoil)")
               .Define("higgs_hadronic_theta",    "JetClusteringUtils::get_theta(higgs_hadronic)")
               .Define("higgs_hadronic_recoil_theta",    "JetClusteringUtils::get_theta(higgs_hadronic_recoil)")
               #.Define("zed_hadronic_charge","ReconstructedParticle::get_charge(zed_hadronic)")
               # define missing momentum / counters ISR
               .Define('missingET_px', 'MissingET.momentum.x')
               .Define('missingET_py', 'MissingET.momentum.y')
               .Define('missingET_pz', 'MissingET.momentum.z')
               .Define('missingET_e', 'MissingET.energy')
               # get cosTheta miss
               .Define('missingET_costheta', 'APCHiggsTools::get_cosTheta_miss(missingET_px,missingET_py,missingET_pz,missingET_e)')


                #Necessary variables for WW fusion
               .Define("status1_nue",  "FCCAnalyses::MCParticle::sel_pdgID( 12, true) ( status1 )")
               .Define("nue_origin2",  "LLRHiggsTools::get_leptons_origin( status1_nue, Particle, Particle0 )")
               .Define("hardsub_nueV", "LLRHiggsTools::sel_leptons_origin( status1_nue, nue_origin2, -11) ") #No Z in WZP6 sample, have to go over the e+e-
               .Define("n_hardsub_nue",  "FCCAnalyses::MCParticle::get_n( hardsub_nueV ) ")

               .Define("hardsub_nue",  "FCCAnalyses::MCParticle::sel_pdgID( 12, false) ( hardsub_nueV )")
               .Define("hardsub_nuebar",  "FCCAnalyses::MCParticle::sel_pdgID( -12, false) ( hardsub_nueV )")
               #.Filter( " FCCAnalyses::MCParticle::get_n( hardsub_eminus ) == 1 && FCCAnalyses::MCParticle::get_n( hardsub_eplus ) == 1 ")
               .Define("n_nue",    "return hardsub_nue.size();")
               .Define("n_nuebar",    "return hardsub_nuebar.size();")

               .Define("hardsub_nue_tlv",  "FCCAnalyses::MCParticle::get_tlv(  hardsub_nue) ")
               .Define("hardsub_nuebar_tlv",  "FCCAnalyses::MCParticle::get_tlv(  hardsub_nuebar) ")
               .Define("mass_nuenue", "return ( hardsub_nue_tlv[0] + hardsub_nuebar_tlv[0]).M() ;" ) #M_nuenue in WZP6


               .Define("zedsub_nueV", "LLRHiggsTools::sel_leptons_origin( status1_nue, nue_origin2, 23) ")
               .Define("n_zedsub_nue",  "FCCAnalyses::MCParticle::get_n( zedsub_nueV ) ")

               .Define("zedsub_nue",  "FCCAnalyses::MCParticle::sel_pdgID( 12, false) ( zedsub_nueV )")
               .Define("zedsub_nuebar",  "FCCAnalyses::MCParticle::sel_pdgID( -12, false) ( zedsub_nueV )")
               #.Filter( " FCCAnalyses::MCParticle::get_n( zedsub_eminus ) == 1 && FCCAnalyses::MCParticle::get_n( zedsub_eplus ) == 1 ")
               .Define("n_znue",    "return zedsub_nue.size();")
               .Define("n_znuebar",    "return zedsub_nuebar.size();")

               .Define("zedsub_nue_tlv",  "FCCAnalyses::MCParticle::get_tlv(  zedsub_nue) ")
               .Define("zedsub_nuebar_tlv",  "FCCAnalyses::MCParticle::get_tlv(  zedsub_nuebar) ")
               .Define("mass_Znuenue", "return ( zedsub_nue_tlv[0] + zedsub_nuebar_tlv[0]).M() ;" ) #M_nuenue in p8

               #Necessary variables for ZZ fusion / Z(ee)H(inclusive)
               .Alias("Electron0", "Electron#0.index")
               # define the electron collection
               .Define("electrons",  "ReconstructedParticle::get(Electron0, ReconstructedParticles)")
               #select electron on pT
               .Define("selected_electrons", "ReconstructedParticle::sel_pt(15.)(electrons)")

               .Define("selected_electrons_pt", "ReconstructedParticle::get_pt(selected_electrons)") 
               # create branch with electron rapidity
               .Define("selected_electrons_y",  "ReconstructedParticle::get_y(selected_electrons)") 
               # create branch with electron total momentum
               .Define("selected_electrons_p",     "ReconstructedParticle::get_p(selected_electrons)")
               # create branch with electron energy 
               .Define("selected_electrons_e",     "ReconstructedParticle::get_e(selected_electrons)")
               # find zed candidates from  di-electron resonances  
               .Define("zed_leptonicE",         "APCHiggsTools::resonanceZBuilder(91.188)(selected_electrons)")
               # write branch with zed mass
               .Define("zed_leptonicE_m",       "ReconstructedParticle::get_mass(zed_leptonicE)")
               # write branch with zed transverse momenta
               .Define("zed_leptonicE_pt",      "ReconstructedParticle::get_pt(zed_leptonicE)")
               .Define("zed_leptonicE_recoil",  "ReconstructedParticle::recoilBuilder(365.)(zed_leptonicE)")
               # write branch with recoil mass
               .Define("zed_leptonicE_recoil_m","ReconstructedParticle::get_mass(zed_leptonicE_recoil)")
               .Define("zed_leptonicE_recoil_pt","ReconstructedParticle::get_pt(zed_leptonicE_recoil)")
               .Define("zed_leptonicE_charge","ReconstructedParticle::get_charge(zed_leptonicE)")

               .Define("status1_e",  "FCCAnalyses::MCParticle::sel_pdgID( 11, true) ( status1 )")
               .Define("e_origin",  "LLRHiggsTools::get_leptons_origin( status1_e, Particle, Particle0 )")
               .Define("hardsub_e", "LLRHiggsTools::sel_leptons_origin( status1_e, e_origin, 0) ")
               .Define("n_hardsub_e",  "FCCAnalyses::MCParticle::get_n( hardsub_e ) ")

               .Define("hardsub_eminus",  "FCCAnalyses::MCParticle::sel_pdgID( 11, false) ( hardsub_e )")
               .Define("hardsub_eplus",  "FCCAnalyses::MCParticle::sel_pdgID( -11, false) ( hardsub_e )")
               #.Filter( " FCCAnalyses::MCParticle::get_n( hardsub_eminus ) == 1 && FCCAnalyses::MCParticle::get_n( hardsub_eplus ) == 1 ")
               .Define("n_eminus",    "return hardsub_eminus.size();")
               .Define("n_eplus",    "return hardsub_eplus.size();")

               .Define("hardsub_eminus_tlv",  "FCCAnalyses::MCParticle::get_tlv(  hardsub_eminus) ")
               .Define("hardsub_eplus_tlv",  "FCCAnalyses::MCParticle::get_tlv(  hardsub_eplus) ")
               .Define("mass_ee", "return ( hardsub_eminus_tlv[0] + hardsub_eplus_tlv[0]).M() ;" )

               .Define("zedsub_e", "LLRHiggsTools::sel_leptons_origin( status1_e, e_origin, 23) ")
               .Define("n_zedsub_e",  "FCCAnalyses::MCParticle::get_n( zedsub_e ) ")

               .Define("zedsub_eminus",  "FCCAnalyses::MCParticle::sel_pdgID( 11, false) ( zedsub_e )")
               .Define("zedsub_eplus",  "FCCAnalyses::MCParticle::sel_pdgID( -11, false) ( zedsub_e )")
               #.Filter( " FCCAnalyses::MCParticle::get_n( zedsub_eminus ) == 1 && FCCAnalyses::MCParticle::get_n( zedsub_eplus ) == 1 ")
               .Define("n_zeminus",    "return zedsub_eminus.size();")
               .Define("n_zeplus",    "return zedsub_eplus.size();")

               .Define("zedsub_eminus_tlv",  "FCCAnalyses::MCParticle::get_tlv(  zedsub_eminus) ")
               .Define("zedsub_eplus_tlv",  "FCCAnalyses::MCParticle::get_tlv(  zedsub_eplus) ")
               .Define("mass_Zee", "return ( zedsub_eminus_tlv[0] + zedsub_eplus_tlv[0]).M() ;" )

                #Necessary variables for Z(mumu)H inclusive
               .Alias("Muon0", "Muon#0.index")
               # define the muon collection
               .Define("muons",  "ReconstructedParticle::get(Muon0, ReconstructedParticles)")
               #select muons on pT
               .Define("selected_muons", "ReconstructedParticle::sel_pt(15.)(muons)")
               # create branch with muon transverse momentum
               .Define("selected_muons_pt", "ReconstructedParticle::get_pt(selected_muons)") 
               # create branch with muon rapidity
               .Define("selected_muons_y",  "ReconstructedParticle::get_y(selected_muons)") 
               # create branch with muon total momentum
               .Define("selected_muons_p",     "ReconstructedParticle::get_p(selected_muons)")
               # create branch with muon energy 
               .Define("selected_muons_e",     "ReconstructedParticle::get_e(selected_muons)")
               # find zed candidates from  di-muon resonances  
               .Define("zed_leptonicM",         "APCHiggsTools::resonanceZBuilder(91.188)(selected_muons)")
               # write branch with zed mass
               .Define("zed_leptonicM_m",       "ReconstructedParticle::get_mass(zed_leptonicM)")
               # write branch with zed transverse momenta
               .Define("zed_leptonicM_pt",      "ReconstructedParticle::get_pt(zed_leptonicM)")
               # calculate recoil of zed_leptonic
               .Define("zed_leptonicM_recoil",  "ReconstructedParticle::recoilBuilder(365.)(zed_leptonicM)")
               # write branch with recoil mass
               .Define("zed_leptonicM_recoil_m","ReconstructedParticle::get_mass(zed_leptonicM_recoil)")
               .Define("zed_leptonicM_recoil_pt","ReconstructedParticle::get_pt(zed_leptonicM_recoil)")
               .Define("zed_leptonicM_charge","ReconstructedParticle::get_charge(zed_leptonicM)")

                #Necessary variables for Z(qq)H inclusive
               .Define("zed_hadronic",         "LLRHiggsTools::jetResonanceBuilder(91.188)(jets_kt)")
               .Define("zed_hadronic_subjets", "LLRHiggsTools::get_compositeSubJets(zed_hadronic)")
               .Define("zed_hadronic_subjets_pt1",  "LLRHiggsTools::get_subjetpt(0, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_pt2",  "LLRHiggsTools::get_subjetpt(1, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_pl1",  "LLRHiggsTools::get_subjetpl(0, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_pl2",  "LLRHiggsTools::get_subjetpl(1, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_E1",  "LLRHiggsTools::get_subjetE(0, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_E2",  "LLRHiggsTools::get_subjetE(1, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_Eta1",  "LLRHiggsTools::get_subjetEta(0, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_Eta2",  "LLRHiggsTools::get_subjetEta(1, zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_theta",  "JetClusteringUtils::get_theta(zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_acoll",  "LLRHiggsTools::get_subjetAcoll(zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_acollPaPb",  "LLRHiggsTools::get_subjetAcollPaPb(zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_DeltaPhi",  "LLRHiggsTools::get_subjetDeltaPhi(zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_DeltaEta",  "LLRHiggsTools::get_subjetDeltaEta(zed_hadronic_subjets)")
               .Define("zed_hadronic_subjets_flavor",  "JetTaggingUtils::get_flavour(zed_hadronic_subjets, Particle)")
               .Define("zed_hadronic_subjets_btag",    "JetTaggingUtils::get_btag(zed_hadronic_subjets_flavor, 0.80, 0.08, 0.01, 0.01)")
               .Define("zed_hadronic_subjets_ctag",    "JetTaggingUtils::get_ctag(zed_hadronic_subjets_flavor, 0.60, 0.10, 0.01, 0.03)")
               .Define("zed_hadronic_subjets_ltag",    "JetTaggingUtils::get_ltag(zed_hadronic_subjets_flavor, 0.80)")
               .Define("zed_hadronic_subjets_btag_true",    "JetTaggingUtils::get_btag(zed_hadronic_subjets_flavor, 1.0)")
               .Define("zed_hadronic_subjets_ctag_true",    "JetTaggingUtils::get_ctag(zed_hadronic_subjets_flavor, 1.0)")
               .Define("zed_hadronic_subjets_ltag_true",    "JetTaggingUtils::get_ltag(zed_hadronic_subjets_flavor, 1.0)")


               .Define("zed_hadronic_m",       "JetClusteringUtils::get_m(zed_hadronic)")
               .Define("zed_hadronic_pt",       "JetClusteringUtils::get_pt(zed_hadronic)")
               .Define("zed_hadronic_pl",       "JetClusteringUtils::get_pz(zed_hadronic)")
               # write branch with zed transverse momenta
               #.Define("zed_hadronic_pt",      "ReconstructedParticle::get_pt(zed_hadronic)")
               # calculate recoil of zed_hadronic
               .Define("zed_hadronic_recoil",  "LLRHiggsTools::jetRecoilBuilder(365.)(zed_hadronic)")
               # write branch with recoil mass
               .Define("zed_hadronic_recoil_m","JetClusteringUtils::get_m(zed_hadronic_recoil)")
               .Define("zed_hadronic_recoil_pt","JetClusteringUtils::get_pt(zed_hadronic_recoil)")
               .Define("zed_hadronic_recoil_pl","JetClusteringUtils::get_pz(zed_hadronic_recoil)")
               .Define("zed_hadronic_theta",    "JetClusteringUtils::get_theta(zed_hadronic)")
               .Define("zed_hadronic_recoil_theta",    "JetClusteringUtils::get_theta(zed_hadronic_recoil)")

                #get MC higgs particles
               .Define("MCHiggs1",       "FCCAnalyses::MCParticle::sel_pdgID(25, false)(status1)") #Final states
               .Define("MCHiggs2",       "FCCAnalyses::MCParticle::sel_pdgID(25, false)(status2)") #Intermediate ones
               .Define("MCHiggs1_Theta", "FCCAnalyses::MCParticle::get_theta(MCHiggs1)")
               .Define("MCHiggs2_Theta", "FCCAnalyses::MCParticle::get_theta(MCHiggs2)")
        )
        return df2

    #__________________________________________________________
    #Mandatory: output function, please make sure you return the branchlist as a python list
    def output():
        branchList = [
            "selected_bjets_pt",
                "jets_kt_btag",
                "jets_kt_ctag",
                "selected_bjets_m",
                "higgs_hadronic_m",
                "higgs_hadronic_pt",
                "higgs_hadronic_recoil_m",
                "higgs_hadronic_recoil_pt",
                "selected_bjet_ht",
                "higgs_hadronic_theta",
                "higgs_hadronic_recoil_theta",
                "higgs_hadronic_subjets_pt2",
                "higgs_hadronic_subjets_theta",
                "higgs_hadronic_subjets_pt1",
                "higgs_hadronic_subjets_E1",
                "higgs_hadronic_subjets_E2",
                "higgs_hadronic_subjets_Eta1",
                "higgs_hadronic_subjets_Eta2",
                "higgs_hadronic_subjets_acoll",
                "higgs_hadronic_subjets_acollPaPb",
                "higgs_hadronic_subjets_DeltaPhi",
                "higgs_hadronic_subjets_DeltaEta",
                "higgs_hadronic_subjets_flavor",
                "higgs_hadronic_subjets_btag",
                "higgs_hadronic_subjets_ctag",
                "higgs_hadronic_subjets_ltag",
                "higgs_hadronic_subjets_btag_true",
                "higgs_hadronic_subjets_ctag_true",
                "higgs_hadronic_subjets_ltag_true",
                "jetNo",
                "bjetNo",
                "cjetNo",
                "missingET_px",
                "missingET_py",
                "missingET_pz",
                "missingET_e",
                "missingET_costheta",
                "jet_ht",
                "higgs_hadronic_pl",
                "higgs_hadronic_recoil_pl",
                "higgs_hadronic_subjets_pl1",
                "higgs_hadronic_subjets_pl2",
                "NmatchedMuons",
                "NmatchedElectrons",
                
                #Necessary variables for WW fusion
                "ZEvts",
                "WEvts",
                "NuMEvts",
                "NuTEvts",
                "number_of_nues",
                "number_of_numus",
                "number_of_nutaus",
                "number_of_nuesf",
                "number_of_numusf",
                "number_of_nutausf",
                "number_of_zeds",
                "ne_corrected",
                "n_hardsub_nue",
                "n_nue",
                "n_nuebar",
                "mass_nuenue",
                "n_znue",
                "n_znuebar",
                "mass_Znuenue",
                "n_zedsub_nue",

                #Necessary variables for ZZ fusion / Z(ee)H inclusive
                "selected_electrons_pt",
                "selected_electrons_y",
                "selected_electrons_p",
                "selected_electrons_e",
                "n_eminus",
                "n_eplus",
                "zed_leptonicE_m",
                "zed_leptonicE_pt",
                "zed_leptonicE_charge",
                "zed_leptonicE_recoil_m",
                "zed_leptonicE_recoil_pt",
                "n_hardsub_e",
                "mass_ee",
                "n_zeplus",
                "n_zeminus",
                "n_zedsub_e",
                "mass_Zee",

                #Neccesary variables for Z(mumu)H inclusive
                "selected_muons_pt",
                "selected_muons_y",
                "selected_muons_p",
                "selected_muons_e",
                "zed_leptonicM_pt",
                "zed_leptonicM_m",
                "zed_leptonicM_charge",
                "zed_leptonicM_recoil_m",
                "zed_leptonicM_recoil_pt",

                #Necessary variables for Z(qq)H inclusive
                "zed_hadronic_m",
                "zed_hadronic_pt",
                "zed_hadronic_recoil_m",
                "zed_hadronic_recoil_pt",
                "zed_hadronic_theta",
                "zed_hadronic_recoil_theta",
                "zed_hadronic_subjets_pt2",
                "zed_hadronic_subjets_theta",
                "zed_hadronic_subjets_pt1",
                "zed_hadronic_subjets_E1",
                "zed_hadronic_subjets_E2",
                "zed_hadronic_subjets_Eta1",
                "zed_hadronic_subjets_Eta2",
                "zed_hadronic_subjets_acoll",
                "zed_hadronic_subjets_flavor",
                "zed_hadronic_subjets_btag",
                "zed_hadronic_subjets_ctag",
                "zed_hadronic_subjets_ltag",
                "zed_hadronic_subjets_btag_true",
                "zed_hadronic_subjets_ctag_true",
                "zed_hadronic_subjets_ltag_true",
                "zed_hadronic_pl",
                "zed_hadronic_recoil_pl",
                "zed_hadronic_subjets_pl1",
                "zed_hadronic_subjets_pl2",
                "zed_hadronic_subjets_acollPaPb",
                "zed_hadronic_subjets_DeltaPhi",
                "zed_hadronic_subjets_DeltaEta",

                "MCHiggs1_Theta",
                "MCHiggs2_Theta"
        ]
        return branchList
