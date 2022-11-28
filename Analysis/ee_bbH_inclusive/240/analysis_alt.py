import sys
import ROOT

print ("Load cxx analyzers ... ",)
ROOT.gSystem.Load("libedm4hep")
ROOT.gSystem.Load("libpodio")
ROOT.gSystem.Load("libFCCAnalyses")
#ROOT.gSystem.Load("libFCCAnalysesHiggs")
ROOT.gErrorIgnoreLevel = ROOT.kFatal
_edm  = ROOT.edm4hep.ReconstructedParticleData()
_pod  = ROOT.podio.ObjectID()
_fcc  = ROOT.dummyLoader
#_higgs  = ROOT.dummyLoaderHiggs

print ('edm4hep  ',_edm)
print ('podio    ',_pod)
print ('fccana   ',_fcc)
#print ('higgs   ',_higgs)

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
               .Alias("Jet3","Jet#3.index") 
               .Define("jets",            "ReconstructedParticle::get(Jet3, Jet)")
               .Define("JET_btag",        "ReconstructedParticle::getJet_btag(Jet3, ParticleIDs, ParticleIDs_0)")
               #Number of tags per event
               .Define("EVT_nbtag",       "ReconstructedParticle::getJet_ntags(JET_btag)")

               #select jetpt
               .Define("selected_jets",   "ReconstructedParticle::sel_pt(25.)(jets)")
               .Define("selected_jets_pt","ReconstructedParticle::get_pt(selected_jets)")

               #.Define("selected_jets", "ReconstructedParticle::sel_pt(60.)(Jet)")
               # create branch with electron rapidity
               #.Define("selected_electrons_y",  "ReconstructedParticle::get_y(selected_electrons)") 
               # create branch with electron total momentum
               #.Define("selected_electrons_p",     "ReconstructedParticle::get_p(selected_electrons)")
               # create branch with electron energy 
               #.Define("selected_electrons_e",     "ReconstructedParticle::get_e(selected_electrons)")
               
               # find zed candidates from  di-jet resonances  
               #.Define("zed_hadronic",         "ReconstructedParticle::resonanceBuilder(91)(jetconstituents_antikt)")
               # write branch with zed mass
               #.Define("zed_hadronic_m",       "ReconstructedParticle::get_mass(zed_hadronic)")
               # write branch with zed transverse momenta
               #.Define("zed_hadronic_pt",      "ReconstructedParticle::get_pt(zed_hadronic)")
               # calculate recoil of zed_hadronic
               #.Define("zed_hadronic_recoil",  "ReconstructedParticle::recoilBuilder(240)(zed_hadronic)")
               # write branch with recoil mass
               #.Define("zed_hadronic_recoil_m","ReconstructedParticle::get_mass(zed_hadronic_recoil)")
               #.Define("zed_hadronic_charge","ReconstructedParticle::get_charge(zed_hadronic)")
               # define missing momentum / counters ISR
               #.Define('missingET_px', 'MissingET.momentum.x')
               #.Define('missingET_py', 'MissingET.momentum.y')
               #.Define('missingET_pz', 'MissingET.momentum.z')
               #.Define('missingET_e', 'MissingET.energy')
               # get cosTheta miss
               #.Define('missingET_costheta', 'APCHiggsTools::get_cosTheta_miss(missingET_px,missingET_py,missingET_pz,missingET_e)')
        )

        


        # select branches for output file
        branchList = ROOT.vector('string')()
        for branchName in [
                "JET_btag",
                "EVT_nbtag",
                "selected_jets_pt"
                #"selected_electrons_pt",
                #"selected_electrons_y",
                #"selected_electrons_p",
                #"selected_electrons_e",
                #"zed_hadronic_pt",
                #"zed_hadronic_m",
                #"zed_hadronic_charge",
                #"zed_hadronic_recoil_m",
                #"missingET_costheta"
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