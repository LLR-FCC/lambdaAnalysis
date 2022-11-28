import ROOT

# global parameters
intLumi        = 5e+06 #in pb-1
ana_tex        = 'e^{+}e^{-} #rightarrow ZH #rightarrow #mu^{+}#mu^{-} + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/categories/ZmumuH/plots/'

variables = ['mz','mz_zoom','leptonic_recoil_m','leptonic_recoil_m_zoom','leptonic_recoil_m_zoom2', 'leptonic_pt']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
selections['ZH']   = ["sel_ZmumuH","sel_ZmumuH1", "sel_ZmumuH2", "sel_ZmumuH3", "sel_ZmumuH4", "selAll"]
selections['ZH_2'] = ["sel_ZmumuH","sel_ZmumuH1", "sel_ZmumuH2", "sel_ZmumuH3", "sel_ZmumuH4", "selAll"]

extralabel = {}
extralabel['selAll'] = "No selection"
extralabel['sel_ZmumuH'] = "Selection: N_{Z} = 1"
extralabel['sel_ZmumuH1'] = "Selection: N_{Z} = 1; M_{Tij} #in #[]{86, 96} GeV"
extralabel['sel_ZmumuH2'] = "Selection: N_{Z} = 1; M_{Tij} #in #[]{86, 96} GeV, M_{Rec} #in #[]{120, 140} GeV"
extralabel['sel_ZmumuH3'] = "Selection: sel_ZmumuH2 cuts; p_{Tij} #in #[]{20, 70} GeV"
extralabel['sel_ZmumuH4'] = "Final selection"

colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['Zll'] = ROOT.kOrange
colors['ggmm'] = ROOT.kBlack

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_mumuH_ecm240']},
               'backgrounds':{'WW':['p8_ee_WW_ecm240'],
                              'ZZ':['p8_ee_ZZ_ecm240'],
                              'Zll':['p8_ee_Zll_ecm240'],
                              'ggmm':['wzp6_gaga_mumu_60_ecm240']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_mumuH_ecm240']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm240','p8_ee_ZZ_ecm240'],
                                'Zll':['p8_ee_Zll_ecm240'],
                                'ggmm':['wzp6_gaga_mumu_60_ecm240']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['Zll'] = 'Z #rightarrow ll'
legend['ggmm'] = '#gamma #gamma #rightarrow #mu^{+}#mu^{-}'



