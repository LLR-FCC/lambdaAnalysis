import sys
import ROOT

print ("Load cxx analyzers ... ",)
ROOT.gSystem.Load("libedm4hep")
ROOT.gSystem.Load("libpodio")
ROOT.gSystem.Load("libFCCAnalyses")
ROOT.gSystem.Load("libFCCAnalysesHiggs")
ROOT.gErrorIgnoreLevel = ROOT.kFatal
_edm  = ROOT.edm4hep.ReconstructedParticleData()
_pod  = ROOT.podio.ObjectID()
_fcc  = ROOT.dummyLoader
_higgs  = ROOT.dummyLoaderHiggs

print ('edm4hep  ',_edm)
print ('podio    ',_pod)
print ('fccana   ',_fcc)
print ('higgs   ',_higgs)

class analysis():

    #__________________________________________________________
    def __init__(self, inputlist, outname, ncpu):
        self.outname = outname
        if ".root" not in outname:
            self.outname+=".root"

        ROOT.ROOT.EnableImplicitMT(ncpu)

        self.df = ROOT.RDataFrame("events", inputlist)
        print (" done")
    #__________________________________________________________
    def run(self):
        df2 = (self.df
               #.Alias("Jet3","Jet#3.index") 
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

               .Define("selected_bjets_pt", "JetClusteringUtils::get_pt(selected_bjets)") #m??ssen jets noch recombinen
               .Define("selected_bjets_m", "JetClusteringUtils::get_m(selected_bjets)")

               .Define("selected_bjet_ht",  "LLRHiggsTools::get_ht(selected_bjets)")

               #.Define("selected_jets", "ReconstructedParticle::sel_pt(60.)(Jet)")
               # create branch with electron rapidity
               #.Define("selected_electrons_y",  "ReconstructedParticle::get_y(selected_electrons)") 
               # create branch with electron total momentum
               #.Define("selected_electrons_p",     "ReconstructedParticle::get_p(selected_electrons)")
               # create branch with electron energy 
               #.Define("selected_electrons_e",     "ReconstructedParticle::get_e(selected_electrons)")
               
               # find zed candidates from  di-jet resonances  
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
               .Define("jetNo",  "LLRHiggsTools::get_jetNo(jets_kt)")
               .Define("bjetNo",  "LLRHiggsTools::get_jetNo(selected_bjets)")
               .Define("cjetNo",  "LLRHiggsTools::get_jetNo(selected_cjets)")
               .Define("jet_ht",  "LLRHiggsTools::get_ht(jets_kt)")
               # write branch with zed mass
               .Define("zed_hadronic_m",       "JetClusteringUtils::get_m(zed_hadronic)")
               .Define("zed_hadronic_pt",       "JetClusteringUtils::get_pt(zed_hadronic)")
               .Define("zed_hadronic_pl",       "JetClusteringUtils::get_pz(zed_hadronic)")
               # write branch with zed transverse momenta
               #.Define("zed_hadronic_pt",      "ReconstructedParticle::get_pt(zed_hadronic)")
               # calculate recoil of zed_hadronic
               .Define("zed_hadronic_recoil",  "LLRHiggsTools::jetRecoilBuilder(240.)(zed_hadronic)")
               # write branch with recoil mass
               .Define("zed_hadronic_recoil_m","JetClusteringUtils::get_m(zed_hadronic_recoil)")
               .Define("zed_hadronic_recoil_pt","JetClusteringUtils::get_pt(zed_hadronic_recoil)")
               .Define("zed_hadronic_recoil_pl","JetClusteringUtils::get_pz(zed_hadronic_recoil)")
               .Define("zed_hadronic_theta",    "JetClusteringUtils::get_theta(zed_hadronic)")
               .Define("zed_hadronic_recoil_theta",    "JetClusteringUtils::get_theta(zed_hadronic_recoil)")
               #.Define("zed_hadronic_charge","ReconstructedParticle::get_charge(zed_hadronic)")
               # define missing momentum / counters ISR
               .Define('missingET_px', 'MissingET.momentum.x')
               .Define('missingET_py', 'MissingET.momentum.y')
               .Define('missingET_pz', 'MissingET.momentum.z')
               .Define('missingET_e', 'MissingET.energy')
               # get cosTheta miss
               .Define('missingET_costheta', 'APCHiggsTools::get_cosTheta_miss(missingET_px,missingET_py,missingET_pz,missingET_e)')
        )

        


        # select branches for output file
        branchList = ROOT.vector('string')()
        for branchName in [
                "selected_bjets_pt",
                "jets_kt_btag",
                "jets_kt_ctag",
                "selected_bjets_m",
                "zed_hadronic_m",
                "zed_hadronic_pt",
                "zed_hadronic_recoil_m",
                "zed_hadronic_recoil_pt",
                "selected_bjet_ht",
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
                "jetNo",
                "bjetNo",
                "cjetNo",
                "missingET_px",
                "missingET_py",
                "missingET_pz",
                "missingET_e",
                "missingET_costheta",
                "jet_ht",
                "zed_hadronic_pl",
                "zed_hadronic_recoil_pl",
                "zed_hadronic_subjets_pl1",
                "zed_hadronic_subjets_pl2",
                "zed_hadronic_subjets_acollPaPb",
                "zed_hadronic_subjets_DeltaPhi",
                "zed_hadronic_subjets_DeltaEta"
                ]:
            branchList.push_back(branchName)
        df2.Snapshot("events", self.outname, branchList)

# example call for standalone file
# python examples/FCCee/higgs/mH-recoil/mumu/analysis.py /eos/experiment/fcc/ee/generation/DelphesEvents/fcc_tmp/p8_ee_ZH_ecm240/events_058720051.root
if __name__ == "__main__":

    if len(sys.argv)==1:
        print ("usage:")
        print ("python ",sys.argv[0]," file.root")
        sys.exit(3)
    infile = sys.argv[1]
    outDir = sys.argv[0].replace(sys.argv[0].split('/')[0],'outputs').replace('analysis.py','')+'/'
    import os
    os.system("mkdir -p {}".format(outDir))
    outfile = outDir+infile.split('/')[-1]
    ncpus = 0
    print ('outfile  ',outfile)
    analysis = analysis(infile, outfile, ncpus)
    analysis.run()

    tf = ROOT.TFile(infile)
    entries = tf.events.GetEntries()
    p = ROOT.TParameter(int)( "eventsProcessed", entries)
    outf=ROOT.TFile(outfile,"UPDATE")
    p.Write()