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
               # define an alias for muon index collection
               #.Alias("Muon0", "Muon#0.index")
               # define the muon collection
               .Define("rawbottom",  "MCParticle::sel_pdgID(5, true)(Particle)")
               .Define("truebottom",  "MCParticle::sel_partons(rawbottom)")
               #select muons on pT
               .Define("selected_bottoms", "MCParticle::sel_pt(5.)(truebottom)")
               # find zed candidates from  di-muon resonances  
               .Define("zed_hadronic_truth",         "MCParticle::resonanceBuilder(91)(selected_bottoms)")
               # write branch with zed mass
               .Define("zed_hadronic_m_truth",       "MCParticle::get_mass(zed_hadronic_truth)")
               # write branch with zed transverse momenta
               .Define("zed_hadronic_pt_truth",      "MCParticle::get_pt(zed_hadronic_truth)")
               # calculate recoil of zed_hadronic
               .Define("zed_hadronic_recoil_truth",  "MCParticle::recoilBuilder(240)(zed_hadronic_truth)")
               # write branch with recoil mass
               .Define("zed_hadronic_recoil_m_truth","MCParticle::get_mass(zed_hadronic_recoil_truth)")
               .Define("zed_hadronic_charge_truth","MCParticle::get_charge(zed_hadronic_truth)")
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
                "selected_muons_pt",
                "selected_muons_y",
                "selected_muons_p",
                "selected_muons_e",
                "zed_hadronic_pt",
                "zed_hadronic_m",
                "zed_hadronic_charge",
                "zed_hadronic_recoil_m",
                "missingET_costheta"
                
               
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