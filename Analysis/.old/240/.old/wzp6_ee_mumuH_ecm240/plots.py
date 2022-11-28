import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
ana_tex        = 'e^{+}e^{-} #rightarrow ZH #rightarrow #mu^{+}#mu^{-} + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = ''
formats        = ['png','pdf']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = 'plots/'

variables = ['mz','mz_zoom','leptonic_recoil_m','leptonic_recoil_m_zoom', 'leptonic_pt']

###Dictionary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
selections['ZH']   = ["sel0","sel1", "sel2", "sel3"]

extralabel = {}
extralabel['sel0'] = "Selection: N_{Z} = 1"
extralabel['sel1'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV"
extralabel['sel2'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 120 GeV < M_{Recoil} < 140 GeV"
extralabel['sel3'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 120 GeV < M_{Recoil} < 140 GeV; 20 GeV < p_{T} < 70 GeV"

colors = {}
colors['ZH'] = ROOT.kRed

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_mumuH_ecm240']},
    'backgrounds':{'ZH':['wzp6_ee_mumuH_ecm240']}
           }

legend = {}
legend['ZH'] = 'ZH'
