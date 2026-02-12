
[
    // Math mode
	{trigger: "mk", replacement: "$$0$", options: "tA"},
	{trigger: "dm", replacement: "$$\n\\begin{align}\n$0\n\\end{align}\n$$", options: "tAw"},
	{trigger: "beg", replacement: "\\begin{$0}\n$1\n\\end{$0}", options: "mA"},

	// Statistikk-Shortcuts
	// {trigger: "E(", replacement: "\\text{E}\\left[ $0 \\right] $1", options: "mA"},
	// {trigger: "Var(", replacement: "\\text{Var}\\left[ $0 \\right] $1", options: "mA"},
	// {trigger: "Cov(", replacement: "\\text{Cov}\\left[ $0 \\right] $1", options: "mA"},
	// {trigger: "SD(", replacement: "\\text{SD}\\left[ $0 \\right] $1", options: "mA"},
	// {trigger: "Corr(", replacement: "\\text{Corr}\\left[ $0 \\right] $1", options: "mA"},
	// {trigger: "bin(", replacement: "\\text{bin}\\left( $0 \\right) $1", options: "mA"},
	// {trigger: "kji", replacement: "\\chi_{${0:n}}^{2} $1", options: "mA"},

	//Matte
	{trigger: "tran", replacement: "^{T}", options: "mA"},
	{trigger: "Tran", replacement: "\\mathbf{${0:x}} ^{T} \\mathbf{${1:y}} $2", options: "mA"},
	{trigger: "iprod", replacement: "( \\mathbf{${0:x}},\\mathbf{${1:y}}) $2", options: "mA"},
	{trigger: "Iprod", replacement: "( \\mathbf{${0:v}}_{${1:k}} , \\mathbf{${2:v}}_{${3:k}} ) $4", options: "mA"},
	{trigger: "Len", replacement: "\\lVert \\mathbf{$0}$1 \\rVert^{2} $2", options: "mA", priority: 1},
	{trigger: "adj", replacement: "^{*}", options: "mA"},
	{trigger: "Adj", replacement: "\\mathbf{${0:x}} ^{*} \\mathbf{${1:y}} $2", options: "mA"},
	{trigger: "what", replacement: "\\widehat{$0}$1", options: "mA"},
	{trigger: "Eval", replacement: "\\left[ $0 \\right] _{${1:-\\infty}}^{${2:\\infty}} $3", options: "mA"},
	{trigger: "rand", replacement: "\\partial ${0:\\Omega} $1", options: "mA"},
	{trigger: "ranb", replacement: "\\Big|_{\\partial ${0:\\Omega} } $1", options: "mA"},
	{trigger: "\\mathbb{R}", replacement: "\\mathbb{R}^{${0:n}} $1", options: "m"},
	{trigger: "dpar", replacement: "\\dfrac{ \\partial^{2} ${0:f} }{ \\partial ${1:x_{1}} \\partial ${2:x_{2}} } $3", options: "mA"},
	{trigger: "pard", replacement: "\\dfrac{ \\partial^{2} ${0:f} }{ \\partial ${1:x_{1}}^{2}} $2", options: "mA"},
	{trigger: "part", replacement: "\\partial_{${0:x}} ${1:f}", options: "mA"},
	{trigger: "goesto", replacement: "\\xrightarrow[${0:x} \\to ${1:\\infty}]{$2} $3", options: "mA"},
	
	{trigger: "def=", replacement: "\\triangleq $0", options: "mA"},
	{trigger: "SI", replacement: "\\mathrm{\\, $0}$1", options: "mA"},
	
	//Lei av å skrive det samme om og om igjen
	{trigger: "divergens", replacement: "\\dfrac{ \\partial f_{1} }{ \\partial x_{1} } +\\dfrac{ \\partial f_{2} }{ \\partial x_{2} } +\\dfrac{ \\partial f_{3} }{ \\partial x_{3} } $0", options: "mA"},
	{trigger: "kule", replacement: "(r,\\theta,\\varphi) $0", options: "mA"},
	
	// RegTek
	{trigger: "eig(", replacement: "\\text{eig}\\left( $0 \\right) $1", options: "mA"},
	{trigger: "ang", replacement: "\\angle $0", options: "mA"},

	// Random
	{trigger: "   ", replacement: "\\, ", options: "mA"},

    // Dashes
	// {trigger: "--", replacement: "–", options: "tA"},
	// {trigger: "–-", replacement: "—", options: "tA"},
	// {trigger: "—-", replacement: "---", options: "tA"},

    // Greek letters
	{trigger: "@a", replacement: "\\alpha", options: "mA"},
	{trigger: "@b", replacement: "\\beta", options: "mA"},
	{trigger: "@g", replacement: "\\gamma", options: "mA"},
	{trigger: "@G", replacement: "\\Gamma", options: "mA"},
	{trigger: "@d", replacement: "\\delta", options: "mA"},
	{trigger: "@D", replacement: "\\Delta", options: "mA"},
	{trigger: "@e", replacement: "\\epsilon", options: "mA"},
	{trigger: ":e", replacement: "\\varepsilon", options: "mA"},
	{trigger: "@z", replacement: "\\zeta", options: "mA"},
	{trigger: "@t", replacement: "\\theta", options: "mA"},
	{trigger: "@T", replacement: "\\Theta", options: "mA"},
	{trigger: ":t", replacement: "\\vartheta", options: "mA"},
	{trigger: "@i", replacement: "\\iota", options: "mA"},
	{trigger: "@k", replacement: "\\kappa", options: "mA"},
	{trigger: "@l", replacement: "\\lambda", options: "mA"},
	{trigger: "@L", replacement: "\\Lambda", options: "mA"},
	{trigger: "@s", replacement: "\\sigma", options: "mA"},
	{trigger: "@S", replacement: "\\Sigma", options: "mA"},
	{trigger: "@u", replacement: "\\upsilon", options: "mA"},
	{trigger: "@U", replacement: "\\Upsilon", options: "mA"},
	{trigger: "@p", replacement: "\\psi", options: "mA"},
	{trigger: "@P", replacement: "\\Psi", options: "mA"},
	{trigger: "Psi", replacement: "\\Psi", options: "mA"},
	{trigger: "@f", replacement: "\\phi", options: "mA"},
	{trigger: "@F", replacement: "\\Phi", options: "mA"},
	{trigger: ":f", replacement: "\\varphi", options: "mA"},
	{trigger: "@o", replacement: "\\omega", options: "mA"},
	{trigger: "@O", replacement: "\\Omega", options: "mA"},
	{trigger: "@n", replacement: "\\nabla", options: "mA"},
	{trigger: "ome", replacement: "\\omega", options: "mA"},
	{trigger: "Ome", replacement: "\\Omega", options: "mA"},
    {trigger: "lap", replacement: "\\mathcal{L}\\left\\{ $0 \\right\\}$1", options: "mA"},
    {trigger: "ilap", replacement: "\\mathcal{L}^{-1}\\left\\{ $0 \\right\\}$1", options: "mA"},

    // Text environment
    {trigger: "text", replacement: "\\text{$0}$1", options: "mA"},
    {trigger: "\"", replacement: "\\text{$0}$1", options: "mA"},

    // Basic operations
    {trigger: "sr", replacement: "^{2}", options: "mA"},
	{trigger: "cb", replacement: "^{3}", options: "mA"},
	{trigger: "rd", replacement: "^{$0}$1", options: "mA"},
	{trigger: "_", replacement: "_{$0}$1", options: "mA"},
	{trigger: "sts", replacement: "_\\text{$0}$1", options: "mA"},
	{trigger: "sq", replacement: "\\sqrt{ $0 }$1", options: "mA"},
	{trigger: "//", replacement: "\\dfrac{$0}{$1}$2", options: "mA"},
	{trigger: "ee", replacement: "e^{ $0 }$1", options: "mA", priority: -1},
    {trigger: "invs", replacement: "^{-1}", options: "mA"},
    {trigger: /([A-Za-z])(\d)/, replacement: "[[0]]_{[[1]]}", options: "rmA", description: "Auto letter subscript", priority: -1},

    {trigger: /([^\\])(exp|log|ln)/, replacement: "[[0]]\\[[1]]", options: "rmA"},
    {trigger: "conj", replacement: "^{*}", options: "mA"},
    {trigger: "Re", replacement: "\\mathrm{Re}$1", options: "mA"},
	{trigger: "Im", replacement: "\\mathrm{Im}$1", options: "mA"},
    {trigger: "bf", replacement: "\\mathbf{$0}$1", options: "mA"},
	{trigger: "rm", replacement: "\\mathrm{$0}$1", options: "mA"},
    {trigger: "bb", replacement: "\\mathbb{$0}$1", options: "mA"},
    {trigger: "cal", replacement: "\\mathcal{$0}$1", options: "mA"},
    {trigger: "tag", replacement: "\\tag{${0:1}}$1", options: "mA"},

    {trigger: "hsp", replacement: "\\hspace{${0:2}em}$1", options: "mA"},
    
    // Linear algebra
    {trigger: /([^\\])(det)/, replacement: "[[0]]\\[[1]]", options: "rmA"},
    {trigger: "trace", replacement: "\\mathrm{Tr}", options: "mA"},

    // More operations
	{trigger: "([a-zA-Z])hat", replacement: "\\hat{[[0]]}", options: "rmA", priority: -1},
    {trigger: "([a-zA-Z])bar", replacement: "\\bar{[[0]]}", options: "rmA"},
	{trigger: "([a-zA-Z])dot", replacement: "\\dot{[[0]]}", options: "rmA", priority: -1},
	{trigger: "([a-zA-Z])ddot", replacement: "\\ddot{[[0]]}", options: "rmA", priority: 1},
	{trigger: "([a-zA-Z])tilde", replacement: "\\tilde{[[0]]}", options: "rmA"},
	{trigger: "([a-zA-Z])und", replacement: "\\underline{[[0]]}", options: "rmA"},
	{trigger: "([a-zA-Z])vec", replacement: "\\vec{[[0]]}", options: "rmA"},
    {trigger: "([a-zA-Z]),\\.", replacement: "\\mathbf{[[0]]}", options: "rmA"},
	{trigger: "([a-zA-Z])\\.,", replacement: "\\mathbf{[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}),\\.", replacement: "\\boldsymbol{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK})\\.,", replacement: "\\boldsymbol{\\[[0]]}", options: "rmA"},

	{trigger: "hat", replacement: "\\hat{$0}$1", options: "mA", priority: -1},
    {trigger: "bar", replacement: "\\bar{$0}$1", options: "mA"},
	{trigger: "dot", replacement: "\\dot{$0}$1", options: "mA", priority: -1},
	{trigger: "ddot", replacement: "\\ddot{$0}$1", options: "mA"},
	{trigger: "dddot", replacement: "\\dddot{$0}$1", options: "mA", priority: 2},
	{trigger: "cdot", replacement: "\\cdot $0", options: "mA"},
	{trigger: "tilde", replacement: "\\tilde{$0}$1", options: "mA"},
	{trigger: "und", replacement: "\\underline{$0}$1", options: "mA"},
    {trigger: "over", replacement: "\\overline{$0}$1", options: "mA"},
	{trigger: "vec", replacement: "\\vec{$0}$1", options: "mA"},

    // More auto letter subscript
    {trigger: /([A-Za-z])_(\d\d)/, replacement: "[[0]]_{[[1]]}", options: "rmA"},
	{trigger: /\\hat{([A-Za-z])}(\d)/, replacement: "\\hat{[[0]]}_{[[1]]}", options: "rmA"},
	{trigger: /\\vec{([A-Za-z])}(\d)/, replacement: "\\vec{[[0]]}_{[[1]]}", options: "rmA"},
    {trigger: /\\bar{([A-Za-z])}(\d)/, replacement: "\\bar{[[0]]}_{[[1]]}", options: "rmA"},
    {trigger: /\\dot{([A-Za-z])}(\d)/, replacement: "\\dot{[[0]]}_{[[1]]}", options: "rmA"},
    {trigger: /\\ddot{([A-Za-z])}(\d)/, replacement: "\\ddot{[[0]]}_{[[1]]}", options: "rmA"},
	{trigger: /\\mathbf{([A-Za-z])}(\d)/, replacement: "\\mathbf{[[0]]}_{[[1]]}", options: "rmA"},
	{trigger: /([A-Za-z])_{(\d)}(\d)/, replacement: "[[0]]_{[[1]][[2]]}", options: "rmA"},

    {trigger: /([a-zA-Z])\1/, replacement: "_{[[0]]}", options: "m", priority: -1},
    {trigger: "nn", replacement: "_{n}", options: "mA", priority: -1},
	{trigger: "\\xii", replacement: "x_{i}", options: "mA", priority: 1},
	{trigger: "xjj", replacement: "x_{j}", options: "mA"},
	// {trigger: "xp1", replacement: "x_{n+1}", options: "mA"},
    {trigger: "tt", replacement: "(t)", options: "mA"},
	{trigger: "yii", replacement: "y_{i}", options: "mA"},
	{trigger: "yjj", replacement: "y_{j}", options: "mA"},
    {trigger: "fx", replacement: "f(x)", options: "mA"},
    // {trigger: /(\D)n(\d)/, replacement: "[[0]]_{n${0:+}[[1]]}", options: "mA"},

    // Symbols
    {trigger: "ooo", replacement: "\\infty $0", options: "mA"},
	{trigger: "sum", replacement: "\\sum", options: "mA", priority: -1},
	{trigger: "prod", replacement: "\\prod", options: "mA"},
	{trigger: "\\sum", replacement: "\\sum_{${0:i}=${1:1}}^{${2:n}} $3", options: "m"},
	// {trigger: "\\sum", replacement: "\\sum_{${0:n}=${1:0}}^{${2:\\infty}} $3", options: "m"},
	{trigger: "isum", replacement: "\\sum_{n=-\\infty}^{\\infty} $1", options: "mA"},
	{trigger: "\\prod", replacement: "\\prod_{${0:i}=${1:1}}^{${2:n}} $3", options: "m"},
    {trigger: "lim", replacement: "\\lim_{ ${0:n} \\to ${1:\\infty} } $2", options: "mA"},
    {trigger: "cup", replacement: "\\bigcup_{${0:i}=${1:1}}^{${2:N}} $3", options: "m"},
    {trigger: "+-", replacement: "\\pm $0", options: "mA"},
	{trigger: "-+", replacement: "\\mp $0", options: "mA"},
    {trigger: "...", replacement: "\\dots $0", options: "mA"},
    {trigger: "v...", replacement: "\\vdots $0", options: "mA"},
    {trigger: "d...", replacement: "\\ddots $0", options: "mA"},
    {trigger: "nabl", replacement: "\\nabla $0", options: "mA"},
	{trigger: "del", replacement: "\\nabla $0", options: "mA"},
    {trigger: "xx", replacement: "\\times $0", options: "mA"},
    {trigger: "**", replacement: "\\cdot $0", options: "mA"},
    {trigger: "para", replacement: "\\parallel $0", options: "mA"},

	{trigger: "===", replacement: "\\equiv $0", options: "mA"},
    {trigger: "!=", replacement: "\\neq $0", options: "mA"},
	{trigger: ">=", replacement: "\\geq $0", options: "mA"},
	{trigger: "<=", replacement: "\\leq $0", options: "mA"},
	{trigger: ">>", replacement: "\\gg $0", options: "mA"},
	{trigger: "<<", replacement: "\\ll $0", options: "mA"},
	{trigger: "simm", replacement: "\\sim $0", options: "mA"},
	{trigger: "sim=", replacement: "\\simeq $0", options: "mA"},
    {trigger: "prop", replacement: "\\propto $0", options: "mA"},
    {trigger: "app", replacement: "\\approx $0", options: "mA"},


    {trigger: "<->", replacement: "\\leftrightarrow $0", options: "mA"},
	{trigger: "->", replacement: "\\to $0", options: "mA"},
	{trigger: "!>", replacement: "\\mapsto $0", options: "mA"},
    {trigger: "=>", replacement: "\\implies $0", options: "mA"},
	{trigger: "=<", replacement: "\\impliedby $0", options: "mA"},

	{trigger: "and", replacement: "\\cap $0", options: "mA"},
	{trigger: "orr", replacement: "\\cup $0", options: "mA"},
	{trigger: "inn", replacement: "\\in $0", options: "mA"},
	{trigger: "notin", replacement: "\\not\\in $0", options: "mA"},
    {trigger: "\\\\\\", replacement: "\\setminus $0", options: "mA"},
    {trigger: "sub=", replacement: "\\subseteq $0", options: "mA"},
    {trigger: "sup=", replacement: "\\supseteq $0", options: "mA"},
	{trigger: "eset", replacement: "\\emptyset $0", options: "mA"},
	{trigger: "set", replacement: "\\{ $0 \\}$1", options: "mA"},
	{trigger: "e\\xi sts", replacement: "\\exists $0", options: "mA", priority: 1},
    {trigger: "deg", replacement: "\\degree  $0", options: "mA"},
    {trigger: "arg", replacement: "\\arg $0", options: "mA"},

	{trigger: "LL", replacement: "\\mathcal{L}", options: "mA"},
	{trigger: "HH", replacement: "\\mathcal{H}", options: "mA"},
	{trigger: "CC", replacement: "\\mathbb{C}", options: "mA"},
	{trigger: "RR", replacement: "\\mathbb{R}", options: "mA"},
	{trigger: "ZZ", replacement: "\\mathbb{Z}", options: "mA"},
	{trigger: "NN", replacement: "\\mathbb{N}", options: "mA"},

    // Handle spaces and backslashes

    // Snippet variables can be used as shortcuts when writing snippets.
    // For example, ${GREEK} below is shorthand for "alpha|beta|gamma|Gamma|delta|..."
    // You can edit snippet variables under the Advanced snippet settings section.

	{trigger: "([^\\\\])(${GREEK})", replacement: "[[0]]\\[[1]]", options: "rmA", description: "Add backslash before Greek letters"},
	{trigger: "([^\\\\])(${SYMBOL})", replacement: "[[0]]\\[[1]] ", options: "rmA", description: "Add backslash before symbols"},

    // Insert space after Greek letters and symbols
	{trigger: "\\\\(${GREEK}|${SYMBOL}|${MORE_SYMBOLS})([A-Za-z])", replacement: "\\[[0]] [[1]]", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) sr", replacement: "\\[[0]]^{2}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) cb", replacement: "\\[[0]]^{3}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) rd", replacement: "\\[[0]]^{$0}$1", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) hat", replacement: "\\hat{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) dot", replacement: "\\dot{\\[[0]]}", options: "rmA"},
    {trigger: "\\\\(${GREEK}|${SYMBOL}) ddot", replacement: "\\ddot{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) bar", replacement: "\\bar{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) vec", replacement: "\\vec{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) tilde", replacement: "\\tilde{\\[[0]]}", options: "rmA"},
	{trigger: "\\\\(${GREEK}|${SYMBOL}) und", replacement: "\\underline{\\[[0]]}", options: "rmA"},


    // Derivatives and integrals
    {trigger: "par", replacement: "\\dfrac{ \\partial ${0:f} }{ \\partial ${1:x} } $2", options: "m"},
    {trigger: "pat", replacement: "\\dfrac{ \\partial }{ \\partial t } $0", options: "m"},
    {trigger: /pa([A-Za-z])(\\(${GREEK})|[A-Za-z])/, replacement: "\\dfrac{ \\partial [[0]] }{ \\partial [[1]] } ", options: "rm"},
    {trigger: "ddt", replacement: "\\dfrac{d}{dt} ", options: "mA"},

    {trigger: /([^\\])int/, replacement: "[[0]]\\int", options: "mA", priority: -1},
    {trigger: "\\int", replacement: "\\int_{${0:\\Omega}} $1 \\, d${2:x} $3", options: "m"},
    {trigger: "dint", replacement: "\\int_{${0:0}}^{${1:1}} $2 \\, d${3:t} $4", options: "mA"},
    {trigger: "oint", replacement: "\\oint", options: "mA"},
	{trigger: "iint", replacement: "\\iint", options: "mA"},
	{trigger: "\\iint", replacement: "\\iint $0 \\, d${1:t} $2", options: "m"},
    {trigger: "iiint", replacement: "\\iiint", options: "mA"},
    {trigger: "\\iiint", replacement: "\\iiint $0 \\, d${1:t} $2", options: "m"},
    {trigger: "oinf", replacement: "\\int_{0}^{\\infty} $0 \\, d${1:t} $2", options: "mA"},
	{trigger: "infi", replacement: "\\int_{-\\infty}^{\\infty} $0 \\, d${1:t} $2", options: "mA"},
    {trigger: "eval", replacement: "\\Bigg|_{${0:-\\infty}}^{${1:\\infty}} $2", options: "mA"},
    {trigger: "Four", replacement: "\\int_{-T/2}^{T/2} $0 \\, d${1:t} $2", options: "mA"},
    {trigger: "four", replacement: "\\int_{-\\pi}^{\\pi} $0 \\, d${1:t} $2", options: "mA"},


    // Trigonometry
    {trigger: /([^\\])(arcsin|sin|arccos|cos|arctan|tan|csc|sec|cot)/, replacement: "[[0]]\\[[1]]", options: "rmA", description: "Add backslash before trig funcs"},

    {trigger: /\\(arcsin|sin|arccos|cos|arctan|tan|csc|sec|cot)([A-Za-gi-z])/,
     replacement: "\\[[0]] [[1]]", options: "rmA",
     description: "Add space after trig funcs. Skips letter h to allow sinh, cosh, etc."},

    {trigger: /\\(sinh|cosh|tanh|coth)([A-Za-z])/,
     replacement: "\\[[0]] [[1]]", options: "rmA",
     description: "Add space after hyperbolic trig funcs"},


    // Visual operations
	{trigger: "U", replacement: "\\underbrace{ ${VISUAL} }_{ $0 }", options: "mA"},
	{trigger: "O", replacement: "\\overbrace{ ${VISUAL} }^{ $0 }", options: "mA"},
	{trigger: "B", replacement: "\\underset{ $0 }{ ${VISUAL} }", options: "mA"},
	{trigger: "C", replacement: "\\cancel{ ${VISUAL} }", options: "mA"},
	{trigger: "K", replacement: "\\cancelto{ $0 }{ ${VISUAL} }", options: "mA"},
	{trigger: "S", replacement: "\\sqrt{ ${VISUAL} }", options: "mA"},


    // Physics
	{trigger: "kbt", replacement: "k_{B}T", options: "mA"},
	{trigger: "msun", replacement: "M_{\\odot}", options: "mA"},

    // Quantum mechanics
    {trigger: "dag", replacement: "^{\\dagger}", options: "mA"},
	{trigger: "o+", replacement: "\\oplus ", options: "mA"},
	{trigger: "ox", replacement: "\\otimes ", options: "mA"},
    {trigger: "bra", replacement: "\\bra{$0} $1", options: "mA"},
	{trigger: "ket", replacement: "\\ket{$0} $1", options: "mA"},
	{trigger: "brk", replacement: "\\braket{ $0 | $1 } $2", options: "mA"},
    {trigger: "outer", replacement: "\\ket{${0:\\psi}} \\bra{${0:\\psi}} $1", options: "mA"},

    // Chemistry
	{trigger: "pu", replacement: "\\pu{ $0 }", options: "mA"},
	{trigger: "cee", replacement: "\\ce{ $0 }", options: "mA"},
	{trigger: "he4", replacement: "{}^{4}_{2}He ", options: "mA"},
	{trigger: "he3", replacement: "{}^{3}_{2}He ", options: "mA"},
	{trigger: "iso", replacement: "{}^{${0:4}}_{${1:2}}${2:He}", options: "mA"},


    // Environments
	{trigger: "pmat", replacement: "\\begin{pmatrix}\n$0\n\\end{pmatrix}", options: "MA"},
	{trigger: "bmat", replacement: "\\begin{bmatrix}\n$0\n\\end{bmatrix}", options: "MA"},
	{trigger: "Bmat", replacement: "\\begin{Bmatrix}\n$0\n\\end{Bmatrix}", options: "MA"},
	{trigger: "vmat", replacement: "\\begin{vmatrix}\n$0\n\\end{vmatrix}", options: "MA"},
	{trigger: "Vmat", replacement: "\\begin{Vmatrix}\n$0\n\\end{Vmatrix}", options: "MA"},
	{trigger: "matrix", replacement: "\\begin{matrix}\n$0\n\\end{matrix}", options: "MA"},

	{trigger: "pmat", replacement: "\\begin{pmatrix}$0\\end{pmatrix}", options: "nA"},
	{trigger: "bmat", replacement: "\\begin{bmatrix}$0\\end{bmatrix}", options: "nA"},
	{trigger: "Bmat", replacement: "\\begin{Bmatrix}$0\\end{Bmatrix}", options: "nA"},
	{trigger: "vmat", replacement: "\\begin{vmatrix}$0\\end{vmatrix}", options: "nA"},
	{trigger: "Vmat", replacement: "\\begin{Vmatrix}$0\\end{Vmatrix}", options: "nA"},
	{trigger: "matrix", replacement: "\\begin{matrix}$0\\end{matrix}", options: "nA"},

	{trigger: "cases", replacement: "\\begin{cases}\n$0\n\\end{cases}", options: "mA"},
	{trigger: "align", replacement: "\\begin{align}\n$0\n\\end{align}", options: "mA"},
	{trigger: "array", replacement: "\\begin{array}{$0}\n$1\n\\end{array}", options: "mA"},
    {trigger: "garr", replacement: "\\begin{array}{ccc|c}\n$0\n\\end{array}", options: "mA"},


    // Brackets
	{trigger: "avg", replacement: "\\langle $0 \\rangle $1", options: "mA"},
	{trigger: "norm", replacement: "\\left\\lvert $0 \\right\\rvert $1", options: "mA", priority: 1},
	{trigger: "Norm", replacement: "\\left\\lVert $0 \\right\\rVert $1", options: "mA", priority: 1},
	{trigger: "ceil", replacement: "\\lceil $0 \\rceil $1", options: "mA"},
	{trigger: "floor", replacement: "\\lfloor $0 \\rfloor $1", options: "mA"},
	{trigger: "mod", replacement: "|$0|$1", options: "mA"},
	{trigger: "(", replacement: "(${VISUAL})", options: "mA"},
	{trigger: "[", replacement: "[${VISUAL}]", options: "mA"},
	{trigger: "{", replacement: "{${VISUAL}}", options: "mA"},
	{trigger: "(", replacement: "($0)$1", options: "mA"},
	{trigger: "{", replacement: "{$0}$1", options: "mA"},
	{trigger: "[", replacement: "[$0]$1", options: "mA"},
	{trigger: "lr(", replacement: "\\left( $0 \\right) $1", options: "mA"},
	{trigger: "lr{", replacement: "\\left\\{ $0 \\right\\} $1", options: "mA"},
	{trigger: "lr[", replacement: "\\left[ $0 \\right] $1", options: "mA"},
	{trigger: "lr|", replacement: "\\left| $0 \\right| $1", options: "mA"},
	{trigger: "lra", replacement: "\\left< $0 \\right> $1", options: "mA"},


    // Misc

    // Automatically convert standalone letters in text to math (except a, A, I, i).
    // (Un-comment to enable)
    {trigger: /([^'æøå])\b([A-HJ-Zb-hj-z])\b([\n\s.,?!:'])/, replacement: "[[0]]$[[1]]$[[2]]", options: "tA"},

    // Automatically convert Greek letters in text to math.
    {trigger: "(${GREEK})([\\n\\s.,?!:'])", replacement: "$\\[[0]]$[[1]]", options: "rtAw"},

    // Automatically convert text of the form "x=2" and "x=n+1" to math.
    {trigger: /([A-Za-z]=\d+)([\n\s.,?!:'])/, replacement: "$[[0]]$[[1]]", options: "rtAw"},
    {trigger: /([A-Za-z]=[A-Za-z][+-]\d+)([\n\s.,?!:'])/, replacement: "$[[0]]$[[1]]", options: "tAw"},


    // Snippet replacements can have placeholders.
	{trigger: "tayl", replacement: "${0:f}(${1:x} + ${2:h}) = ${0:f}(${1:x}) + ${0:f}'(${1:x})${2:h} + ${0:f}''(${1:x}) \\dfrac{${2:h}^{2}}{2!} + \\dots$3", options: "mA", description: "Taylor expansion"},

    // Snippet replacements can also be JavaScript functions.
    // See the documentation for more information.
	{trigger: /iden(\d)/, replacement: (match) => {
		const n = match[1];

		let arr = [];
		for (let j = 0; j < n; j++) {
			arr[j] = [];
			for (let i = 0; i < n; i++) {
				arr[j][i] = (i === j) ? 1 : 0;
			}
		}

		let output = arr.map(el => el.join(" & ")).join(" \\\\\n");
		output = `\\begin{pmatrix}\n${output}\n\\end{pmatrix}`;
		return output;
	}, options: "mA", description: "N x N identity matrix"},
]