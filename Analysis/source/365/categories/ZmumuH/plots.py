import ROOT

# global parameters
intLumi        = 1.5e+06 #in pb-1
ana_tex        = 'e^{+}e^{-} #rightarrow ZH #rightarrow #mu^{+}#mu^{-} + X'
delphesVersion = '3.4.2'
energy         = 365.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/categories/ZmumuH/plots/'

variables = ['mz','mz_zoom','leptonic_recoil_m','leptonic_recoil_m_zoom','leptonic_recoil_m_zoom2', 'leptonic_pt']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
selections['ZH']   = ["sel_ZmumuH","sel_ZmumuH1", "sel_ZmumuH2", "sel_ZmumuH3", "sel_ZmumuH4", "sel_ZmumuH5", "selAll"]
selections['ZH_2'] = ["sel_ZmumuH","sel_ZmumuH1", "sel_ZmumuH2", "sel_ZmumuH3", "sel_ZmumuH4", "sel_ZmumuH5", "selAll"]

extralabel = {}
extralabel['selAll'] = "No selection"
extralabel['sel_ZmumuH'] = "Selection: N_{Z} = 1"
extralabel['sel_ZmumuH1'] = "Selection: N_{Z} = 1; M_{Tij} #in #[]{86, 96} GeV"
extralabel['sel_ZmumuH2'] = "Selection: N_{Z} = 1; M_{Tij} #in #[]{86, 96} GeV, M_{Rec} #in #[]{120, 140} GeV"
extralabel['sel_ZmumuH3'] = "Selection: sel_ZmumuH2 cuts; p_{Tij} #in #[]{20, 70} GeV"
extralabel['sel_ZmumuH4'] = "Selection: sel_ZmumuH2 cuts; p_{Tij} > 70 GeV"
extralabel['sel_ZmumuH5'] = "Selection: sel_ZmumuH2 cuts; p_{Tij} > 80 GeV"

colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['mm'] = ROOT.kOrange
colors['tautau'] = ROOT.kOrange+1
colors['ggmm'] = ROOT.kOrange+2
colors['ll'] = ROOT.kOrange+3


plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_mumuH_ecm365']},
               'backgrounds':{'WW':['p8_ee_WW_ecm365'],
                              'ZZ':['p8_ee_ZZ_ecm365'],
                              'ggmm':['wzp6_gaga_mumu_60_ecm365'],
                              'mm':['wzp6_ee_mumu_ecm365'],
                              'tautau':['wzp6_ee_tautau_ecm365']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_mumuH_ecm365']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365'], 
                 'ggmm':['wzp6_gaga_mumu_60_ecm365'], 
                 'll':['wzp6_ee_mumu_ecm365', 'wzp6_ee_tautau_ecm365']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['mm'] = 'Z #rightarrow #mu^{+}#mu^{-}'
legend['tautau'] = 'Z(#tau^{+}#tau^{-}) #rightarrow #mu^{+}#mu^{-}'
legend['ggmm'] = '#gamma #gamma #rightarrow #mu^{+}#mu^{-}'
legend['ll'] = 'Z #rightarrow l^{+}l^{-}'



