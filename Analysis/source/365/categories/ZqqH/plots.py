import ROOT

# global parameters
intLumi        = 1.5e+06 #in pb-1
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow ij + X'
delphesVersion = '3.4.2'
energy         = 365.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/categories/ZqqH/plots/'
scaleSig       = 1.0
#ana_tex    = 'M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV'
ana_tex        = ''

#variables = ['cJet_No']
#variables = ['m_rec', 'ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'mz', 'FinalClassifier_BDT', 'FinalClassifier_DNN', 'FinalClassifier_MLP']
variables = ['m_rec', 'jet_ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Acoll_PaPb', 'DeltaEta_ij', 'DeltaPhi_ij', 'Jet_No', 'bJet_No', 'cJet_No', 'pT_ij', 'M_ij', 'MET', 'MET_Angle', 'pL_ij', 'pL1', 'pL2', 'FinalClassifier_BDT_bb', 'FinalClassifier_BDT_bj', 'FinalClassifier_BDT_bc', 'FinalClassifier_BDT_cc', 'FinalClassifier_BDT_cj', 'FinalClassifier_BDT_ij']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}

selections['ZH']   = ["sel_noBDT_bbH", "sel_bbH", "sel_noBDT_bcH", "sel_bcH", "sel_bcH1", "sel_bcH2", "sel_bcH3", "sel_noBDT_ccH", "sel_ccH", "sel_ccH1", "sel_ccH2", "sel_noBDT_cjH", "sel_cjH", "sel_cjH1", "sel_cjH2", "sel_noBDT_bjH", "sel_bjH", "sel_bjH1", "sel_bjH2", "sel_noBDT_ijH", "sel_ijH", "sel_ijH1", "sel_ijH2"]
#selections['ZH']   = ["sel_noBDT_cjH", "sel_cjH"]
#selections['VBF']   = ["selVBF_noBDT_VetoM", "selVBF_noBDT_NoVetoM", "selVBF_noBDT_Veto"]



#label={}
#label['selZbbFinal3'] = "M_{Rec} \in [100, 160] GeV"

extralabel = {}
#extralabel['selVBF_noBDT'] = "N_{bH} = 2, #||{#Delta #eta} < 3, HT > 20 GeV, MET > 10 GeV"
#extralabel['selVBF'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589"
#extralabel['selVBF1'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 100 GeV"
#extralabel['selVBF2'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 90 GeV"
#extralabel['selVBF3'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 80 GeV"
#extralabel['selVBF4'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 70 GeV"

extralabel['sel_noBDT_bbH'] = "2e, 2#mu veto, Z#rightarrow bb, M_{bb} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_bbH'] = "sel_noBDT_bbH cut, #beta_{bb} > 0.1651"

extralabel['sel_noBDT_bbHSpecial'] = "2e, 2#mu veto, Z#rightarrow bb, M_{bb} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"

extralabel['sel_noBDT_bcH'] = "2e, 2#mu veto, Z#rightarrow bc, M_{bc} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_bcH'] = "sel_noBDT_bcH cuts, #beta_{bc} > -0.0627"
extralabel['sel_bcH1'] = "sel_bcH cuts, N_{bJet} > 0"
extralabel['sel_bcH2'] = "sel_bcH cuts, N_{bJet} > 0, Acoll_{ij} < 2"
extralabel['sel_bcH3'] = "sel_bcH cuts, N_{bJet} > 0, Acoll_{ij} < 2, #beta_{bc} > 0.10"


extralabel['sel_noBDT_ccH'] = "2e, 2#mu veto, Z#rightarrow cc, M_{cc} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_ccH'] = "sel_noBDT_ccH cuts, #beta_{cc} > 0.0962"
extralabel['sel_ccH1'] = "sel_ccH cuts, #||{cos(#theta_{Miss})} < 0.98"
extralabel['sel_ccH2'] = "sel_ccH cuts, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > 0.3"



extralabel['sel_noBDT_cjH'] = "2e, 2#mu veto, Z#rightarrow cj, M_{cj} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_cjH'] = "sel_noBDT_cjH cuts, #beta_{cj} > 0.2640"
extralabel['sel_cjH1'] = "sel_cjH cuts, #||{cos(#theta_{Miss})} < 0.98"
extralabel['sel_cjH2'] = "sel_cjH cuts, #||{cos(#theta_{Miss})} < 0.98, Acoll_{ij} < 2"

extralabel['sel_noBDT_bjH'] = "2e, 2#mu veto, Z#rightarrow bj, M_{bj} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_bjH'] = "sel_noBDT_bjH cut, #beta_{bj} > 0.1277"
extralabel['sel_bjH1'] = "sel_noBDT_bjH cut, Acoll_{ij} < 2, #beta_{bj} > 0.1277"
extralabel['sel_bjH2'] = "sel_noBDT_bjH cut, Acoll_{ij} < 2, #beta_{bj} > 0.2077"

extralabel['sel_noBDT_ijH'] = "2e, 2#mu veto, Z#rightarrow ij, M_{ij} #in #[]{86, 96} GeV, M_{Rec} #in #[]{100, 160} GeV"
extralabel['sel_ijH'] = "sel_noBDT_ijH cut, #beta_{ij} > 0.2247"
extralabel['sel_ijH1'] = "sel_ijH cut, #||{cos(#theta_{Miss})} < 0.98"
extralabel['sel_ijH2'] = "sel_ijH cut, #||{cos(#theta_{Miss})} < 0.98, Acoll_{ij} < 2"




colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['Zqq'] = ROOT.kOrange+2

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm365']},
               'backgrounds':{'WW':['p8_ee_WW_ecm365'],
                              'ZZ':['p8_ee_ZZ_ecm365'],
                              'Zqq':['p8_ee_Zqq_ecm365']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm365']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365'],
                                'Zqq':['p8_ee_Zqq_ecm365']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['Zqq'] = 'Zqq'


