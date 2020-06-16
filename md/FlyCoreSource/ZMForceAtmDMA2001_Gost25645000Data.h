//---------------------------------------------------------------------------
// ZMForceAtmDMA2001_Gost25645000Data.h
// ���������� ��������� ������������ ��������� �� 
// ���� � 25645.000-2001.
// �. ��������� 06.11.2018.
//---------------------------------------------------------------------------
#ifndef ZMForceAtmDMA2001_Gost25645000DATA_H
#define ZMForceAtmDMA2001_Gost25645000DATA_H

//--------------------------------------------------------------------------------
// ��������� �������� ������ ������ ��������� (�� 120 ��) 
struct LOW_ATM_MODEL_ITEM {
	double h ;
	double a ;
	double k1, k2 ;
};

// �������� ������ ������ ��������� (�� 120 ��)
static LOW_ATM_MODEL_ITEM LowAtmDMA2001[4] = {
	// ��  ��/�3       1/��        1/��2
	{ 20, 1.228,     -9.0764e-2, -2.0452e-3},
	{ 60, 9.013e-2,  -0.16739,    6.2669e-4},
	{100, 3.0447e-4, -0.1356,    -8.13e-4},
	{120, 3.66e-7,   -0.1633,     4.621e-4}} ;

//--------------------------------------------------------------------------------
// �������� ������������� ������������� ����������� 
// ������������ ������� �� ������� ����
static double Ai[9] = {
	-1.66718e-2, -2.44075e-3,   3.08392e-6,
	 2.90115e-6, -4.99606e-8,   3.36327e-10,
	-1.0966e-12,  1.73227e-15, -1.06271e-18 } ;

//--------------------------------------------------------------------------------
// ������������� ������� ��������� ���������� F0, 10-22 ��/(�2 ��)
static double F0fix[7] = {75, 100, 125, 150, 175, 200, 250} ;

//--------------------------------------------------------------------------------
// ������� �������� ���������� ��� ����������� ������� �������������
static double hgi[7][7]= {
	{500,500,500,500,500,500,500},
	{600,700,800,800,900,900,1000},
	{700,700,800,800,900,900,1000},
	{800,800,800,800,800,800,800},
	{600,700,800,800,800,900,800},
	{700,700,800,800,800,900,900},
	{700,700,800,800,800,900,900}} ;

//--------------------------------------------------------------------------------
// ������������ ������ ��������� ���������. ������ �������� ��������
//--------------------------------------------------------------------------------
static double ailow[7][7]= {
	// [��]
	{ 2.57309e+01,  2.75605e+01,  2.85344e+01,  2.91482e+01,  2.94966e+01,  2.97564e+01,  3.00796e+01},
	// [1/��]
	{-4.23306e-01, -4.66242e-01, -4.88303e-01, -5.02424e-01, -5.10952e-01, -5.17820e-01, -5.27712e-01},
	// [1/��2]
	{ 2.62336e-03,  3.00008e-03,  3.17933e-03,  3.29326e-03,  3.36392e-03,  3.42511e-03,  3.52182e-03},
	// [1/��3]
	{-9.29071e-06, -1.08873e-05, -1.15414e-05, -1.19351e-05, -1.21725e-05, -1.23973e-05, -1.27769e-05},
	// [1/��4]
	{ 1.83968e-08,  2.20776e-08,  2.32988e-08,  2.39615e-08,  2.43369e-08,  2.47498e-08,  2.54982e-08},
	// [1/��5]
	{-1.91628e-11, -2.35510e-11, -2.46356e-11, -2.51099e-11, -2.53384e-11, -2.56933e-11, -2.64066e-11},
	// [1/��6]
	{ 8.20168e-15,  1.03109e-14,  1.06444e-14,  1.07148e-14,  1.07169e-14,  1.08203e-14,  1.10731e-14}} ;
static double bilow[5][7]= {
	// [��]
	{ 6.49977e-02,  6.50652e-02,  0.165612,    -5.89144e-02,  4.44639e-03, -0.140165,    -2.04263e-01},
	// [1/��]
	{-3.06873e-03, -3.02445e-03, -4.35142e-03, -1.35850e-03, -2.19289e-03, -4.65788e-04,  1.36515e-04},
	// [1/��2]
	{ 1.95655e-05,  1.93214e-05,  2.51698e-05,  1.21856e-05,  1.58524e-05,  9.29580e-06,  7.80717e-06},
	// [1/��3]
	{-6.66691e-09, -9.73263e-09, -2.25810e-08, -1.94790e-09, -9.50062e-09, -3.94258e-10,  3.04886e-10},
	// [1/��4]
	{-2.07608e-11, -1.22376e-11, -3.53038e-13, -9.95541e-12, -3.79140e-12, -7.30491e-12,	-5.95365e-12}} ;
static double cilow[5][7]= {
	// [��]
	{-0.132579,    -0.132579,    -0.548245,    -0.548245,    -0.545624,    -0.545624,    -0.552086},
	// [1/��]
	{ 2.98530e-03,  2.98530e-03,  8.20121e-03,  8.20121e-03,  7.57748e-03,  7.57748e-03,  7.16294e-03},
	// [1/��2]
	{-2.25849e-05, -2.25849e-05, -4.01156e-05, -4.01156e-05, -3.34243e-05, -3.34243e-05, -2.92525e-05},
	// [1/��3]
	{ 1.20703e-07,  1.20703e-07,  1.14321e-07,  1.14321e-07,  8.38662e-08,  8.38662e-08,  6.48366e-08},
	// [1/��4]
	{-1.24478e-10, -1.24478e-10, -8.71732e-11, -8.71732e-11, -5.59389e-11, -5.59389e-11, -3.80755e-11}} ;
static double n0low[7]= {
	2.058, 2.058, 2.058, 2.058, 2.058, 2.058, 2.058} ;
static double nlow[2][7]= {
	// [1/��]
	{ 5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3},
	// [1/��2]
	{-4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6}} ;
static double fi1low[7]= {
	// ������
	0.5411, 0.5515, 0.5585, 0.5585, 0.5585, 0.5585, 0.5585} ;
static double dilow[4][7]= {
	// [��]
	{-0.0619071,  -0.0619071,  -0.217106,   -0.217106,   -0.199696,   -0.199696,   -0.199696},
	// [1/��]
	{ 3.53963e-3,  3.53963e-3,  6.30628e-3,  6.30628e-3,  6.69745e-3,  6.69745e-3,  6.69745e-3},
	// [1/��2]
	{ 4.98912e-6,  4.98912e-6, -5.65614e-6, -5.65614e-6, -7.68966e-6, -7.68966e-6, -7.68966e-6},
	// [1/��3]
	{-6.89196e-9, -6.89196e-9,  2.85734e-9,  2.85734e-9,  4.04246e-9,  4.04246e-9,  4.04246e-9}} ;
static double eilow[9][7]= {
	// [��]
	{-0.777916,    -0.777739,    -0.570476,    -0.949573,    -0.967598,    -1.02278,     -0.694824},
	// [1/��]
	{ 6.04070e-03,  5.69090e-03,  2.95802e-03,  8.13121e-03,  8.41991e-03,  9.23633e-03,  5.20601e-03},
	// [1/��2]
	{-5.88566e-06,  1.81832e-06,  1.68896e-05, -3.87813e-06, -3.58500e-06, -6.10128e-06,  1.16681e-05},
	// [1/��3]
	{ 6.92343e-08,  3.35689e-08, -4.74756e-09,  2.37694e-08,  1.74801e-08,  1.78211e-08, -1.65494e-08},
	// [1/��4]
	{-9.61190e-11, -5.16839e-11, -1.72711e-11, -2.77469e-11, -1.96221e-11, -1.70073e-11,  5.75301e-12},
	// [��]
	{-0.20902,     -0.17156,     -0.14825,     -0.13287,     -0.122241,    -0.11460,     -0.10524},
	// [��]
	{ 9.75330e-02,  7.98300e-02,  6.88080e-02,  6.16030e-02,  5.65380e-02,  5.31780e-02,  4.85510e-02},
	// [��]
	{-1.18170e-02, -9.43930e-03, -7.98360e-03, -7.08660e-03, -6.43240e-03, -6.04360e-03, -5.35670e-03},
	// [��]
	{ 1.61450e-03,  1.26220e-03,  1.05350e-03,  9.28130e-04,  8.37230e-04,  7.79820e-04,  6.88090e-04}} ;
static double etilow[4][7]= {
	// [��]
	{-0.20807,   -0.17087,   -0.14770,   -0.13240,   -0.12183,   -0.11423,   -0.10493},
	// [��]
	{ 9.4449e-2,  7.7599e-2,  6.7052e-2,  6.0105e-2,  5.5232e-2,  5.1994e-2,  4.7573e-2},
	// [��]
	{-8.7953e-3, -7.1375e-3, -6.0951e-3, -5.4388e-3, -4.9580e-3, -4.6876e-3, -4.1711e-3},
	// [��]
	{ 8.8385e-4,  6.9025e-4,  5.7456e-4,  5.0585e-4,  4.5512e-4,  4.2548e-4,  3.7068e-4}} ;
static double kilow[5][7]= {
	// [��]
	{ 0.404286,     0.046976,     0.0218454,   -0.0555525,   -0.171068,    -0.156258,    -0.27906},
	// [1/��]
	{-6.53925e-03, -5.88767e-04,  2.86090e-04,  1.43513e-03,  3.18684e-03,  2.78232e-03,  4.37978e-03},
	// [1/��2]
	{ 3.04751e-05,  1.19128e-07, -5.94913e-06, -1.11906e-05, -1.86472e-05, -1.56926e-05, -2.13459e-05},
	// [1/��3]
	{-3.34115e-08,  2.08445e-08,  2.80030e-08,  3.47539e-08,  4.44791e-08,  3.48516e-08,  4.02871e-08},
	// [1/��4]
	{ 5.74523e-12, -2.50236e-11, -2.47774e-11, -2.68520e-11, -3.02625e-11, -2.19024e-11, -2.28034e-11}} ;
static double lilow[5][7]= {
	// [��]
	{-0.988325,    -0.975185,    -0.759054,    -1.37655,     -1.21265,     -1.54396,     -1.67664},
	// [1/��]
	{ 9.43604e-03,  8.40266e-03,  5.26528e-03,  1.34777e-02,  1.14399e-02,  1.57732e-02,  1.77194e-02},
	// [1/��2]
	{-2.71945e-05, -1.27491e-05,  6.39465e-06, -2.58760e-05, -1.47726e-05, -3.04193e-05, -3.69498e-05},
	// [1/��3]
	{ 1.19540e-07,  6.22831e-08,  1.09718e-08,  5.50738e-08,  2.78799e-08,  4.59684e-08,  5.09134e-08},
	// [1/��4]
	{-1.36507e-10, -7.19493e-11, -2.62991e-11, -4.39172e-11, -2.26938e-11, -2.84172e-11, -2.82878e-11}} ;

//--------------------------------------------------------------------------------
// ������������ ������ ��������� ���������. ������� �������� ��������
//--------------------------------------------------------------------------------
static double aihi[7][7]= {
	// [��]
	{ 4.98651e+01,  5.81031e+00, -4.78056e+00, -3.36444e+01, -2.65082e+01, -2.34530e+01, -1.62816e+01},
	// [1/��]
	{-3.34292e-01, -3.87883e-02,  2.50162e-02,  2.04460e-01,  1.50087e-01,  1.24743e-01,  7.28713e-02},
	// [1/��2]
	{ 7.39139e-04, -3.52838e-05, -1.75154e-04, -6.11416e-04, -4.42887e-04, -3.58309e-04, -2.04003e-04},
	// [1/��3]
	{-8.88418e-07,  1.51843e-07,  3.04471e-07,  8.49908e-07,  5.91948e-07,  4.57871e-07,  2.32554e-07},
	// [1/��4]
	{ 5.99515e-10, -1.63797e-10, -2.52590e-10, -6.26417e-10, -4.17581e-10, -3.07324e-10, -1.33300e-10},
	// [1/��5]
	{-2.13818e-13,  7.81677e-14,  1.04520e-13,  2.38430e-13,  1.52315e-13,  1.06444e-13,  3.74919e-14},
	// [1/��6]
	{ 3.13667e-17, -1.43386e-17, -1.74870e-17, -3.71372e-17, -2.28438e-17, -1.51634e-17, -4.04570e-18}} ;
static double bihi[5][7]= {
	// [��]
	{ 19.1597,      26.9895,      34.4274,      29.6371,      36.9576,      11.3165,     -14.6575},
	// [1/��]
	{-6.80873e-02, -8.95941e-02, -1.07173e-01, -8.14440e-02, -9.75364e-02, -5.04160e-03,  8.64075e-02},
	// [1/��2]
	{ 9.15651e-05,  1.12400e-04,  1.26243e-04,  8.45828e-05,  9.74067e-05, -2.22200e-05, -1.34306e-04},
	// [1/��3]
	{-5.39353e-08, -6.18513e-08, -6.54690e-08, -3.83526e-08, -4.27077e-08,  2.40539e-08,  8.24585e-08},
	// [1/��4]
	{ 1.16731e-11,  1.25729e-11,  1.26232e-11,  6.41585e-12,  6.96063e-12, -6.71207e-12, -1.77803e-11}} ;
static double cihi[5][7]= {
	// [��]
	{ 26.9231,      26.9231,      29.9244,      29.9244,      17.7196,      17.7196,      1.8336},
	// [1/��]
	{-6.85685e-02, -6.85685e-02, -5.61513e-02, -5.61513e-02, -5.01253e-03, -5.01253e-03,  3.78361e-02},
	// [1/��2]
	{ 6.14236e-05,  6.14236e-05,  2.77330e-05,  2.77330e-05, -3.51915e-05, -3.51915e-05, -6.45005e-05},
	// [1/��3]
	{-2.00812e-08, -2.00812e-08,  4.23239e-09,  4.23239e-09,  3.38521e-08,  3.38521e-08,  3.48538e-08},
	// [1/��4]
	{ 1.22787e-12,  1.22787e-12, -4.16164e-12, -4.16164e-12, -8.67852e-12, -8.67852e-12, -5.87135e-12}} ;
static double n0hi[7]= {
	2.058, 2.058, 2.058, 2.058, 2.058, 2.058, 2.058} ;
static double nhi[2][7]= {
	// [1/��]
	{ 5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3,  5.887e-3},
	// [1/��2]
	{-4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6, -4.012e-6}} ;
static double fi1hi[7]= {
	// ������
	0.5411, 0.5515, 0.5585, 0.5585, 0.5585, 0.5585, 0.5585} ;
static double dihi[4][7]= {
	// [��]
	{ 0.887001,    0.887001,   -0.451254,   -0.451254,   -3.07766,    -3.07766,    -3.07766},
	// [1/��]
	{ 6.25220e-3,  6.25220e-3,  7.87770e-3,  7.87770e-3,  1.29428e-2,  1.29428e-2,  1.29428e-2},
	// [1/��2]
	{-6.91964e-6, -6.91964e-6, -6.07417e-6, -6.07417e-6, -9.67358e-6, -9.67358e-6, -9.67358e-6},
	// [1/��3]
	{ 1.88445e-9,  1.88445e-9,  1.35098e-9,  1.35098e-9,  2.39266e-9,  2.39266e-9,  2.39266e-9}} ;
static double eihi[9][7]= {
	// [��]
	{ 39.0335,      52.6286,      68.4746,      58.422,       7.20188,      21.5948,     -103.303},
	// [1/��]
	{-0.1337,      -0.172381,    -2.15659e-01, -1.66664e-01,  2.16109e-02, -2.02239e-02,  0.391488},
	// [1/��2]
	{ 1.77478e-04,  2.18499e-04,  2.62273e-04,  1.85486e-04, -6.52882e-05, -1.72029e-05, -5.15204e-4},
	// [1/��3]
	{-1.03627e-07, -1.22110e-07, -1.40972e-07, -9.12345e-08,  5.37077e-08,  2.83017e-08,  2.91844e-7},
	// [1/��4]
	{ 2.24068e-11,  2.53442e-11,  2.82285e-11,  1.67118e-11, -1.40950e-11, -8.94486e-12, -6.05856e-11},
	// [��]
	{-0.20902,     -0.17156,     -0.14825,     -0.13287,     -0.122241,    -0.11460,     -0.10524},
	// [��]
	{ 9.75330e-02,  7.98300e-02,  6.88080e-02,  6.16030e-02,  5.65380e-02,  5.31780e-02,  4.8551e-2},
	// [��]
	{-1.18170e-02, -9.43930e-03, -7.98360e-03, -7.08660e-03, -6.43240e-03, -6.04360e-03, -5.3567e-3},
	// [��]
	{ 1.61450e-03,  1.26220e-03,  1.05350e-03,  9.28130e-04,  8.37230e-04,  7.79820e-04,  6.8809e-4}} ;
static double etihi[4][7]= {
	// [��]
	{-0.20807,   -0.17087,   -0.14770,   -0.13240,   -0.12183,   -0.11423,   -0.10493},
	// [��]
	{ 9.4449e-2,  7.7599e-2,  6.7052e-2,  6.0105e-2,  5.5232e-2,  5.1994e-2,  4.7573e-2},
	// [��]
	{-8.7953e-3, -7.1375e-3, -6.0951e-3, -5.4388e-3, -4.9580e-3, -4.6876e-3, -4.1711e-3},
	// [��]
	{ 8.8385e-4,  6.9025e-4,  5.7456e-4,  5.0585e-4,  4.5512e-4,  4.2548e-4,  3.7068e-4}} ;
static double kihi[5][7]= {
	// [��]
	{ 8.91415,      7.95597,      8.88844,      3.2744,      -2.33606,     -3.76622,     -14.9992},
	// [1/��]
	{-2.46654e-02, -1.92438e-02, -2.06477e-02, -5.45880e-04,  1.95394e-02,  2.51806e-02,  6.24112e-02},
	// [1/��2]
	{ 2.60909e-05,  1.70933e-05,  1.73431e-05, -8.38537e-06, -3.40863e-05, -4.13477e-05, -8.64019e-05},
	// [1/��3]
	{-1.24141e-08, -6.43059e-09, -5.97542e-09,  8.18670e-09,  2.23290e-08,  2.62237e-08,  5.00368e-08},
	// [1/��4]
	{ 2.22751e-12,  8.20432e-13,  6.38979e-13, -2.21511e-12, -5.06401e-12, -5.82154e-12, -1.04833e-11}} ;
static double lihi[5][7]= {
	// [��]
	{ 45.1992,      59.8733,      68.3614,      55.2418,      59.6039,      23.9618,     -15.5728},
	// [1/��]
	{-1.56873e-01, -1.98084e-01, -2.11828e-01, -1.53167e-01, -1.57958e-01, -3.42003e-02,  9.36704e-02},
	// [1/��2]
	{ 2.07070e-04,  2.49366e-04,  2.49462e-04,  1.61763e-04,  1.59472e-04,  3.40553e-06, -1.49036e-04},
	// [1/��3]
	{-1.20160e-07, -1.38394e-07, -1.29450e-07, -7.49391e-08, -7.08188e-08,  1.45650e-08,  9.42151e-08},
	// [1/��4]
	{ 2.58235e-11,  2.85472e-11,  2.49748e-11,  1.28582e-11,  1.16949e-11, -5.50719e-12, -2.09610e-11}} ;


//---------------------------------------------------------------------------
#endif //#ifndef ZMForceAtmDMA2001_Gost25645000DATA_H
