typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;


typedef _anon0 type_0[6];
typedef unsigned int type_1[4];
typedef unsigned int type_2[4][6];
typedef _anon0 type_3[6];
typedef _anon0 type_4[8];
typedef unsigned int type_5[4];
typedef unsigned int type_6[4][6];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct _anon1
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon2
{
	_anon0 c1;
	_anon0 c2;
	float r;
};

struct _anon3
{
	_anon0 v[8];
};

struct _anon4
{
	_anon0 c;
	float r;
};


int njIsParalellL2L(_anon1* pLine1, _anon1* pLine2);
int njIsParalellL2PL(_anon1* pLine, _anon1* pPlane);
float njDistanceP2P(_anon0* pPoint1, _anon0* pPoint2);
float njDistanceP2L(_anon0* pPoint, _anon1* pLine, _anon0* pCross);
float njDistanceP2PL(_anon0* pPoint, _anon1* pPlane, _anon0* pCross);
float njDistanceL2L(_anon1* pLine1, _anon1* pLine2, _anon0* pCross1, _anon0* pCross2);
float njDistanceL2PL(_anon1* pLine, _anon1* pPlane, _anon0* pCross);
void njGetPlaneNormal(_anon0* pPoint, _anon0* pVector);
void njGetPlaneNormal2(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pVector);
int njCollisionCheckSS(_anon4* pSphere1, _anon4* pSphere2);
int njCollisionCheckCC(_anon2* pCap1, _anon2* pCap2);
int njCollisionCheckSC(_anon4* pSphere, _anon2* pCapsule);
int njCollisionCheckBS(_anon3* pBox, _anon4* pSphere);
int njCollisionCheckBC(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4AndLine(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPN, _anon1* pLine);
int njCollisionCheckBC2(_anon3* pBox, _anon2* pCapsule);
int njCheckPlane4IncludePoint(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPC);

// 
// Start address: 0x2e3160
int njIsParalellL2L(_anon1* pLine1, _anon1* pLine2)
{
	float fLength;
	float fZ2;
	float fY2;
	float fX2;
	float fZ1;
	float fY1;
	float fX1;
	// Line 65, Address: 0x2e3160, Func Offset: 0
	// Line 70, Address: 0x2e3184, Func Offset: 0x24
	// Line 71, Address: 0x2e3188, Func Offset: 0x28
	// Line 72, Address: 0x2e318c, Func Offset: 0x2c
	// Line 73, Address: 0x2e3194, Func Offset: 0x34
	// Line 78, Address: 0x2e31a8, Func Offset: 0x48
	// Line 79, Address: 0x2e31ac, Func Offset: 0x4c
	// Line 74, Address: 0x2e31b0, Func Offset: 0x50
	// Line 80, Address: 0x2e31b4, Func Offset: 0x54
	// Line 75, Address: 0x2e31b8, Func Offset: 0x58
	// Line 76, Address: 0x2e31bc, Func Offset: 0x5c
	// Line 81, Address: 0x2e31c0, Func Offset: 0x60
	// Line 82, Address: 0x2e31d4, Func Offset: 0x74
	// Line 83, Address: 0x2e31d8, Func Offset: 0x78
	// Line 89, Address: 0x2e31dc, Func Offset: 0x7c
	// Line 84, Address: 0x2e31e4, Func Offset: 0x84
	// Line 89, Address: 0x2e31e8, Func Offset: 0x88
	// Line 96, Address: 0x2e3220, Func Offset: 0xc0
	// Func End, Address: 0x2e3248, Func Offset: 0xe8
}

// 
// Start address: 0x2e3250
int njIsParalellL2PL(_anon1* pLine, _anon1* pPlane)
{
	float fLz;
	float fLy;
	float fLx;
	float fPz;
	float fPy;
	float fPx;
	float fLength;
	// Line 117, Address: 0x2e3250, Func Offset: 0
	// Line 123, Address: 0x2e3274, Func Offset: 0x24
	// Line 124, Address: 0x2e3278, Func Offset: 0x28
	// Line 125, Address: 0x2e327c, Func Offset: 0x2c
	// Line 126, Address: 0x2e3284, Func Offset: 0x34
	// Line 131, Address: 0x2e3298, Func Offset: 0x48
	// Line 132, Address: 0x2e329c, Func Offset: 0x4c
	// Line 127, Address: 0x2e32a0, Func Offset: 0x50
	// Line 133, Address: 0x2e32a4, Func Offset: 0x54
	// Line 128, Address: 0x2e32a8, Func Offset: 0x58
	// Line 129, Address: 0x2e32ac, Func Offset: 0x5c
	// Line 134, Address: 0x2e32b0, Func Offset: 0x60
	// Line 135, Address: 0x2e32c4, Func Offset: 0x74
	// Line 136, Address: 0x2e32c8, Func Offset: 0x78
	// Line 142, Address: 0x2e32cc, Func Offset: 0x7c
	// Line 137, Address: 0x2e32d4, Func Offset: 0x84
	// Line 142, Address: 0x2e32d8, Func Offset: 0x88
	// Line 149, Address: 0x2e3310, Func Offset: 0xc0
	// Func End, Address: 0x2e3338, Func Offset: 0xe8
}

// 
// Start address: 0x2e3340
float njDistanceP2P(_anon0* pPoint1, _anon0* pPoint2)
{
	float fDeltaZ;
	float fDeltaY;
	float fDeltaX;
	// Line 173, Address: 0x2e3340, Func Offset: 0
	// Line 172, Address: 0x2e3348, Func Offset: 0x8
	// Line 174, Address: 0x2e3350, Func Offset: 0x10
	// Line 173, Address: 0x2e3358, Func Offset: 0x18
	// Line 174, Address: 0x2e335c, Func Offset: 0x1c
	// Line 172, Address: 0x2e3360, Func Offset: 0x20
	// Line 175, Address: 0x2e3364, Func Offset: 0x24
	// Func End, Address: 0x2e3378, Func Offset: 0x38
}

// 
// Start address: 0x2e3380
float njDistanceP2L(_anon0* pPoint, _anon1* pLine, _anon0* pCross)
{
	float fDl;
	float fDz;
	float fDy;
	float fDx;
	float fLl;
	float fLz;
	float fLy;
	float fLx;
	// Line 199, Address: 0x2e3380, Func Offset: 0
	// Line 210, Address: 0x2e33a0, Func Offset: 0x20
	// Line 211, Address: 0x2e33a4, Func Offset: 0x24
	// Line 212, Address: 0x2e33a8, Func Offset: 0x28
	// Line 213, Address: 0x2e33b8, Func Offset: 0x38
	// Line 218, Address: 0x2e33cc, Func Offset: 0x4c
	// Line 219, Address: 0x2e33d4, Func Offset: 0x54
	// Line 217, Address: 0x2e33dc, Func Offset: 0x5c
	// Line 214, Address: 0x2e33e4, Func Offset: 0x64
	// Line 218, Address: 0x2e33e8, Func Offset: 0x68
	// Line 219, Address: 0x2e33ec, Func Offset: 0x6c
	// Line 217, Address: 0x2e33f0, Func Offset: 0x70
	// Line 215, Address: 0x2e33f4, Func Offset: 0x74
	// Line 216, Address: 0x2e33f8, Func Offset: 0x78
	// Line 222, Address: 0x2e33fc, Func Offset: 0x7c
	// Line 224, Address: 0x2e3408, Func Offset: 0x88
	// Line 222, Address: 0x2e340c, Func Offset: 0x8c
	// Line 224, Address: 0x2e3410, Func Offset: 0x90
	// Line 226, Address: 0x2e3420, Func Offset: 0xa0
	// Line 228, Address: 0x2e3428, Func Offset: 0xa8
	// Line 229, Address: 0x2e342c, Func Offset: 0xac
	// Line 230, Address: 0x2e3434, Func Offset: 0xb4
	// Line 232, Address: 0x2e343c, Func Offset: 0xbc
	// Line 236, Address: 0x2e3448, Func Offset: 0xc8
	// Line 238, Address: 0x2e3454, Func Offset: 0xd4
	// Line 240, Address: 0x2e345c, Func Offset: 0xdc
	// Line 241, Address: 0x2e3468, Func Offset: 0xe8
	// Line 242, Address: 0x2e3478, Func Offset: 0xf8
	// Line 244, Address: 0x2e3488, Func Offset: 0x108
	// Line 270, Address: 0x2e3494, Func Offset: 0x114
	// Func End, Address: 0x2e34b8, Func Offset: 0x138
}

// 
// Start address: 0x2e34c0
float njDistanceP2PL(_anon0* pPoint, _anon1* pPlane, _anon0* pCross)
{
	float fVz;
	float fVy;
	float fVx;
	float fLength;
	// Line 293, Address: 0x2e34c0, Func Offset: 0
	// Line 298, Address: 0x2e34e0, Func Offset: 0x20
	// Line 299, Address: 0x2e34e4, Func Offset: 0x24
	// Line 300, Address: 0x2e34e8, Func Offset: 0x28
	// Line 301, Address: 0x2e34f8, Func Offset: 0x38
	// Line 307, Address: 0x2e350c, Func Offset: 0x4c
	// Line 302, Address: 0x2e3524, Func Offset: 0x64
	// Line 303, Address: 0x2e3528, Func Offset: 0x68
	// Line 304, Address: 0x2e352c, Func Offset: 0x6c
	// Line 307, Address: 0x2e3530, Func Offset: 0x70
	// Line 313, Address: 0x2e3548, Func Offset: 0x88
	// Line 315, Address: 0x2e3550, Func Offset: 0x90
	// Line 316, Address: 0x2e355c, Func Offset: 0x9c
	// Line 317, Address: 0x2e356c, Func Offset: 0xac
	// Line 320, Address: 0x2e357c, Func Offset: 0xbc
	// Line 321, Address: 0x2e3584, Func Offset: 0xc4
	// Func End, Address: 0x2e35a8, Func Offset: 0xe8
}

// 
// Start address: 0x2e35b0
float njDistanceL2L(_anon1* pLine1, _anon1* pLine2, _anon0* pCross1, _anon0* pCross2)
{
	float fDz;
	float fDy;
	float fDx;
	float fNz;
	float fNy;
	float fNx;
	float fV2z;
	float fV2y;
	float fV2x;
	float fV1z;
	float fV1y;
	float fV1x;
	float fIV;
	float fT;
	// Line 346, Address: 0x2e35b0, Func Offset: 0
	// Line 354, Address: 0x2e35e4, Func Offset: 0x34
	// Line 355, Address: 0x2e35e8, Func Offset: 0x38
	// Line 356, Address: 0x2e35ec, Func Offset: 0x3c
	// Line 357, Address: 0x2e35fc, Func Offset: 0x4c
	// Line 362, Address: 0x2e3614, Func Offset: 0x64
	// Line 363, Address: 0x2e3618, Func Offset: 0x68
	// Line 358, Address: 0x2e361c, Func Offset: 0x6c
	// Line 364, Address: 0x2e3620, Func Offset: 0x70
	// Line 359, Address: 0x2e3624, Func Offset: 0x74
	// Line 360, Address: 0x2e3628, Func Offset: 0x78
	// Line 365, Address: 0x2e362c, Func Offset: 0x7c
	// Line 366, Address: 0x2e3640, Func Offset: 0x90
	// Line 367, Address: 0x2e3644, Func Offset: 0x94
	// Line 368, Address: 0x2e3648, Func Offset: 0x98
	// Line 371, Address: 0x2e364c, Func Offset: 0x9c
	// Line 372, Address: 0x2e365c, Func Offset: 0xac
	// Line 374, Address: 0x2e3684, Func Offset: 0xd4
	// Line 376, Address: 0x2e368c, Func Offset: 0xdc
	// Line 377, Address: 0x2e3694, Func Offset: 0xe4
	// Line 378, Address: 0x2e369c, Func Offset: 0xec
	// Line 380, Address: 0x2e36a4, Func Offset: 0xf4
	// Line 384, Address: 0x2e36bc, Func Offset: 0x10c
	// Line 385, Address: 0x2e36c4, Func Offset: 0x114
	// Line 386, Address: 0x2e36cc, Func Offset: 0x11c
	// Line 384, Address: 0x2e36d4, Func Offset: 0x124
	// Line 385, Address: 0x2e36d8, Func Offset: 0x128
	// Line 389, Address: 0x2e36dc, Func Offset: 0x12c
	// Line 391, Address: 0x2e36ec, Func Offset: 0x13c
	// Line 393, Address: 0x2e36f0, Func Offset: 0x140
	// Line 391, Address: 0x2e36f4, Func Offset: 0x144
	// Line 392, Address: 0x2e36fc, Func Offset: 0x14c
	// Line 391, Address: 0x2e3704, Func Offset: 0x154
	// Line 392, Address: 0x2e3708, Func Offset: 0x158
	// Line 393, Address: 0x2e370c, Func Offset: 0x15c
	// Line 392, Address: 0x2e3718, Func Offset: 0x168
	// Line 394, Address: 0x2e371c, Func Offset: 0x16c
	// Line 396, Address: 0x2e3724, Func Offset: 0x174
	// Line 397, Address: 0x2e3730, Func Offset: 0x180
	// Line 398, Address: 0x2e373c, Func Offset: 0x18c
	// Line 399, Address: 0x2e374c, Func Offset: 0x19c
	// Line 401, Address: 0x2e375c, Func Offset: 0x1ac
	// Line 403, Address: 0x2e3764, Func Offset: 0x1b4
	// Line 404, Address: 0x2e3768, Func Offset: 0x1b8
	// Line 403, Address: 0x2e376c, Func Offset: 0x1bc
	// Line 404, Address: 0x2e3774, Func Offset: 0x1c4
	// Line 405, Address: 0x2e3780, Func Offset: 0x1d0
	// Line 406, Address: 0x2e3790, Func Offset: 0x1e0
	// Line 411, Address: 0x2e37a0, Func Offset: 0x1f0
	// Line 415, Address: 0x2e37a8, Func Offset: 0x1f8
	// Line 412, Address: 0x2e37ac, Func Offset: 0x1fc
	// Line 415, Address: 0x2e37b4, Func Offset: 0x204
	// Line 413, Address: 0x2e37b8, Func Offset: 0x208
	// Line 415, Address: 0x2e37c0, Func Offset: 0x210
	// Line 419, Address: 0x2e37e8, Func Offset: 0x238
	// Line 423, Address: 0x2e380c, Func Offset: 0x25c
	// Func End, Address: 0x2e3844, Func Offset: 0x294
}

// 
// Start address: 0x2e3850
float njDistanceL2PL(_anon1* pLine, _anon1* pPlane, _anon0* pCross)
{
	float fT;
	float fZ;
	float fY;
	float fX;
	float fN;
	float fM;
	float fL;
	float fC;
	float fB;
	float fA;
	// Line 447, Address: 0x2e3850, Func Offset: 0
	// Line 453, Address: 0x2e3880, Func Offset: 0x30
	// Line 454, Address: 0x2e3884, Func Offset: 0x34
	// Line 455, Address: 0x2e3888, Func Offset: 0x38
	// Line 456, Address: 0x2e3898, Func Offset: 0x48
	// Line 461, Address: 0x2e38ac, Func Offset: 0x5c
	// Line 462, Address: 0x2e38b0, Func Offset: 0x60
	// Line 457, Address: 0x2e38b4, Func Offset: 0x64
	// Line 463, Address: 0x2e38b8, Func Offset: 0x68
	// Line 458, Address: 0x2e38bc, Func Offset: 0x6c
	// Line 459, Address: 0x2e38c0, Func Offset: 0x70
	// Line 464, Address: 0x2e38c4, Func Offset: 0x74
	// Line 465, Address: 0x2e38d8, Func Offset: 0x88
	// Line 466, Address: 0x2e38dc, Func Offset: 0x8c
	// Line 467, Address: 0x2e38e0, Func Offset: 0x90
	// Line 469, Address: 0x2e38e4, Func Offset: 0x94
	// Line 471, Address: 0x2e38f0, Func Offset: 0xa0
	// Line 474, Address: 0x2e38f8, Func Offset: 0xa8
	// Line 476, Address: 0x2e3920, Func Offset: 0xd0
	// Line 479, Address: 0x2e3924, Func Offset: 0xd4
	// Line 477, Address: 0x2e3928, Func Offset: 0xd8
	// Line 479, Address: 0x2e392c, Func Offset: 0xdc
	// Line 478, Address: 0x2e3930, Func Offset: 0xe0
	// Line 479, Address: 0x2e3934, Func Offset: 0xe4
	// Line 483, Address: 0x2e3938, Func Offset: 0xe8
	// Line 479, Address: 0x2e393c, Func Offset: 0xec
	// Line 480, Address: 0x2e3960, Func Offset: 0x110
	// Line 481, Address: 0x2e396c, Func Offset: 0x11c
	// Line 482, Address: 0x2e3978, Func Offset: 0x128
	// Line 483, Address: 0x2e3980, Func Offset: 0x130
	// Line 488, Address: 0x2e3988, Func Offset: 0x138
	// Line 492, Address: 0x2e39a0, Func Offset: 0x150
	// Line 493, Address: 0x2e39a4, Func Offset: 0x154
	// Func End, Address: 0x2e39d8, Func Offset: 0x188
}

// 
// Start address: 0x2e39e0
void njGetPlaneNormal(_anon0* pPoint, _anon0* pVector)
{
	_anon0* pP3;
	_anon0* pP2;
	// Line 518, Address: 0x2e39e0, Func Offset: 0
	// Line 519, Address: 0x2e3a14, Func Offset: 0x34
	// Line 520, Address: 0x2e3a48, Func Offset: 0x68
	// Line 521, Address: 0x2e3a78, Func Offset: 0x98
	// Func End, Address: 0x2e3a80, Func Offset: 0xa0
}

// 
// Start address: 0x2e3a80
void njGetPlaneNormal2(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pVector)
{
	// Line 544, Address: 0x2e3a80, Func Offset: 0
	// Line 545, Address: 0x2e3ab4, Func Offset: 0x34
	// Line 546, Address: 0x2e3ae8, Func Offset: 0x68
	// Line 547, Address: 0x2e3b18, Func Offset: 0x98
	// Func End, Address: 0x2e3b20, Func Offset: 0xa0
}

// 
// Start address: 0x2e3b20
int njCollisionCheckSS(_anon4* pSphere1, _anon4* pSphere2)
{
	float fR;
	float fDz;
	float fDy;
	float fDx;
	_anon0* pCenter2;
	_anon0* pCenter1;
	// Line 576, Address: 0x2e3b20, Func Offset: 0
	// Line 578, Address: 0x2e3b28, Func Offset: 0x8
	// Line 577, Address: 0x2e3b30, Func Offset: 0x10
	// Line 580, Address: 0x2e3b38, Func Offset: 0x18
	// Line 576, Address: 0x2e3b3c, Func Offset: 0x1c
	// Line 580, Address: 0x2e3b40, Func Offset: 0x20
	// Line 578, Address: 0x2e3b44, Func Offset: 0x24
	// Line 577, Address: 0x2e3b48, Func Offset: 0x28
	// Line 580, Address: 0x2e3b4c, Func Offset: 0x2c
	// Line 586, Address: 0x2e3b50, Func Offset: 0x30
	// Line 592, Address: 0x2e3b80, Func Offset: 0x60
	// Func End, Address: 0x2e3b88, Func Offset: 0x68
}

// 
// Start address: 0x2e3b90
int njCollisionCheckCC(_anon2* pCap1, _anon2* pCap2)
{
	_anon4 Sphere;
	_anon0 Point2;
	_anon0 Point1;
	float fLength;
	_anon1 Line2;
	_anon1 Line1;
	_anon0* pP22;
	_anon0* pP12;
	// Line 613, Address: 0x2e3b90, Func Offset: 0
	// Line 626, Address: 0x2e3bb0, Func Offset: 0x20
	// Line 622, Address: 0x2e3bc0, Func Offset: 0x30
	// Line 624, Address: 0x2e3bc4, Func Offset: 0x34
	// Line 626, Address: 0x2e3bc8, Func Offset: 0x38
	// Line 627, Address: 0x2e3bd0, Func Offset: 0x40
	// Line 628, Address: 0x2e3be0, Func Offset: 0x50
	// Line 629, Address: 0x2e3bf0, Func Offset: 0x60
	// Line 630, Address: 0x2e3bf8, Func Offset: 0x68
	// Line 631, Address: 0x2e3c00, Func Offset: 0x70
	// Line 632, Address: 0x2e3c08, Func Offset: 0x78
	// Line 641, Address: 0x2e3c10, Func Offset: 0x80
	// Line 632, Address: 0x2e3c14, Func Offset: 0x84
	// Line 633, Address: 0x2e3c1c, Func Offset: 0x8c
	// Line 634, Address: 0x2e3c2c, Func Offset: 0x9c
	// Line 635, Address: 0x2e3c3c, Func Offset: 0xac
	// Line 636, Address: 0x2e3c44, Func Offset: 0xb4
	// Line 637, Address: 0x2e3c4c, Func Offset: 0xbc
	// Line 641, Address: 0x2e3c50, Func Offset: 0xc0
	// Line 644, Address: 0x2e3c64, Func Offset: 0xd4
	// Line 646, Address: 0x2e3c68, Func Offset: 0xd8
	// Line 647, Address: 0x2e3c6c, Func Offset: 0xdc
	// Line 648, Address: 0x2e3c70, Func Offset: 0xe0
	// Line 644, Address: 0x2e3c74, Func Offset: 0xe4
	// Line 645, Address: 0x2e3c78, Func Offset: 0xe8
	// Line 648, Address: 0x2e3c7c, Func Offset: 0xec
	// Line 645, Address: 0x2e3c80, Func Offset: 0xf0
	// Line 646, Address: 0x2e3c84, Func Offset: 0xf4
	// Line 647, Address: 0x2e3c8c, Func Offset: 0xfc
	// Line 648, Address: 0x2e3c90, Func Offset: 0x100
	// Line 649, Address: 0x2e3ca8, Func Offset: 0x118
	// Line 652, Address: 0x2e3cac, Func Offset: 0x11c
	// Line 649, Address: 0x2e3cb4, Func Offset: 0x124
	// Line 650, Address: 0x2e3cb8, Func Offset: 0x128
	// Line 651, Address: 0x2e3cc0, Func Offset: 0x130
	// Line 652, Address: 0x2e3cc4, Func Offset: 0x134
	// Line 660, Address: 0x2e3cdc, Func Offset: 0x14c
	// Line 662, Address: 0x2e3d0c, Func Offset: 0x17c
	// Line 666, Address: 0x2e3d14, Func Offset: 0x184
	// Line 667, Address: 0x2e3d20, Func Offset: 0x190
	// Line 666, Address: 0x2e3d24, Func Offset: 0x194
	// Line 667, Address: 0x2e3d28, Func Offset: 0x198
	// Line 668, Address: 0x2e3d5c, Func Offset: 0x1cc
	// Line 669, Address: 0x2e3d90, Func Offset: 0x200
	// Line 670, Address: 0x2e3d9c, Func Offset: 0x20c
	// Line 669, Address: 0x2e3da0, Func Offset: 0x210
	// Line 670, Address: 0x2e3da4, Func Offset: 0x214
	// Line 671, Address: 0x2e3dd8, Func Offset: 0x248
	// Line 674, Address: 0x2e3e0c, Func Offset: 0x27c
	// Line 677, Address: 0x2e3e40, Func Offset: 0x2b0
	// Func End, Address: 0x2e3e64, Func Offset: 0x2d4
}

// 
// Start address: 0x2e3e70
int njCollisionCheckSC(_anon4* pSphere, _anon2* pCapsule)
{
	_anon0 Point;
	float fLength;
	_anon1 Line;
	_anon0* pP2;
	// Line 698, Address: 0x2e3e70, Func Offset: 0
	// Line 709, Address: 0x2e3e88, Func Offset: 0x18
	// Line 716, Address: 0x2e3e94, Func Offset: 0x24
	// Line 706, Address: 0x2e3e9c, Func Offset: 0x2c
	// Line 709, Address: 0x2e3ea0, Func Offset: 0x30
	// Line 710, Address: 0x2e3ea8, Func Offset: 0x38
	// Line 711, Address: 0x2e3eb8, Func Offset: 0x48
	// Line 712, Address: 0x2e3ec8, Func Offset: 0x58
	// Line 713, Address: 0x2e3ed0, Func Offset: 0x60
	// Line 714, Address: 0x2e3ed8, Func Offset: 0x68
	// Line 716, Address: 0x2e3ee0, Func Offset: 0x70
	// Line 718, Address: 0x2e3f04, Func Offset: 0x94
	// Line 722, Address: 0x2e3f0c, Func Offset: 0x9c
	// Line 723, Address: 0x2e3f18, Func Offset: 0xa8
	// Line 722, Address: 0x2e3f1c, Func Offset: 0xac
	// Line 723, Address: 0x2e3f20, Func Offset: 0xb0
	// Line 724, Address: 0x2e3f54, Func Offset: 0xe4
	// Line 727, Address: 0x2e3f88, Func Offset: 0x118
	// Line 729, Address: 0x2e3fbc, Func Offset: 0x14c
	// Func End, Address: 0x2e3fd8, Func Offset: 0x168
}

// 
// Start address: 0x2e3fe0
int njCollisionCheckBS(_anon3* pBox, _anon4* pSphere)
{
	_anon2 Capsule;
	float fR;
	float fCz;
	float fCy;
	float fCx;
	// Line 750, Address: 0x2e3fe0, Func Offset: 0
	// Line 763, Address: 0x2e4004, Func Offset: 0x24
	// Line 760, Address: 0x2e4008, Func Offset: 0x28
	// Line 757, Address: 0x2e400c, Func Offset: 0x2c
	// Line 758, Address: 0x2e4010, Func Offset: 0x30
	// Line 759, Address: 0x2e4014, Func Offset: 0x34
	// Line 763, Address: 0x2e401c, Func Offset: 0x3c
	// Line 770, Address: 0x2e40a8, Func Offset: 0xc8
	// Line 774, Address: 0x2e40b4, Func Offset: 0xd4
	// Line 775, Address: 0x2e40fc, Func Offset: 0x11c
	// Line 776, Address: 0x2e4144, Func Offset: 0x164
	// Line 779, Address: 0x2e418c, Func Offset: 0x1ac
	// Line 781, Address: 0x2e4190, Func Offset: 0x1b0
	// Line 782, Address: 0x2e4194, Func Offset: 0x1b4
	// Line 783, Address: 0x2e4198, Func Offset: 0x1b8
	// Line 784, Address: 0x2e419c, Func Offset: 0x1bc
	// Line 781, Address: 0x2e41a0, Func Offset: 0x1c0
	// Line 782, Address: 0x2e41a4, Func Offset: 0x1c4
	// Line 785, Address: 0x2e41a8, Func Offset: 0x1c8
	// Line 786, Address: 0x2e41ac, Func Offset: 0x1cc
	// Line 787, Address: 0x2e41b0, Func Offset: 0x1d0
	// Line 782, Address: 0x2e41b4, Func Offset: 0x1d4
	// Line 783, Address: 0x2e41b8, Func Offset: 0x1d8
	// Line 787, Address: 0x2e41bc, Func Offset: 0x1dc
	// Line 783, Address: 0x2e41c0, Func Offset: 0x1e0
	// Line 784, Address: 0x2e41c4, Func Offset: 0x1e4
	// Line 785, Address: 0x2e41cc, Func Offset: 0x1ec
	// Line 786, Address: 0x2e41d4, Func Offset: 0x1f4
	// Line 787, Address: 0x2e41d8, Func Offset: 0x1f8
	// Line 788, Address: 0x2e41f0, Func Offset: 0x210
	// Line 791, Address: 0x2e41f4, Func Offset: 0x214
	// Line 788, Address: 0x2e41fc, Func Offset: 0x21c
	// Line 789, Address: 0x2e4200, Func Offset: 0x220
	// Line 790, Address: 0x2e4208, Func Offset: 0x228
	// Line 791, Address: 0x2e420c, Func Offset: 0x22c
	// Line 792, Address: 0x2e4224, Func Offset: 0x244
	// Line 795, Address: 0x2e4228, Func Offset: 0x248
	// Line 792, Address: 0x2e4230, Func Offset: 0x250
	// Line 793, Address: 0x2e4234, Func Offset: 0x254
	// Line 794, Address: 0x2e423c, Func Offset: 0x25c
	// Line 795, Address: 0x2e4240, Func Offset: 0x260
	// Line 796, Address: 0x2e4258, Func Offset: 0x278
	// Line 799, Address: 0x2e425c, Func Offset: 0x27c
	// Line 796, Address: 0x2e4264, Func Offset: 0x284
	// Line 797, Address: 0x2e4268, Func Offset: 0x288
	// Line 798, Address: 0x2e4270, Func Offset: 0x290
	// Line 799, Address: 0x2e4274, Func Offset: 0x294
	// Line 800, Address: 0x2e428c, Func Offset: 0x2ac
	// Line 803, Address: 0x2e4290, Func Offset: 0x2b0
	// Line 800, Address: 0x2e4298, Func Offset: 0x2b8
	// Line 801, Address: 0x2e429c, Func Offset: 0x2bc
	// Line 802, Address: 0x2e42a4, Func Offset: 0x2c4
	// Line 803, Address: 0x2e42a8, Func Offset: 0x2c8
	// Line 804, Address: 0x2e42c0, Func Offset: 0x2e0
	// Line 807, Address: 0x2e42c4, Func Offset: 0x2e4
	// Line 804, Address: 0x2e42cc, Func Offset: 0x2ec
	// Line 805, Address: 0x2e42d0, Func Offset: 0x2f0
	// Line 806, Address: 0x2e42d8, Func Offset: 0x2f8
	// Line 807, Address: 0x2e42dc, Func Offset: 0x2fc
	// Line 808, Address: 0x2e42f4, Func Offset: 0x314
	// Line 811, Address: 0x2e42f8, Func Offset: 0x318
	// Line 808, Address: 0x2e4300, Func Offset: 0x320
	// Line 809, Address: 0x2e4304, Func Offset: 0x324
	// Line 810, Address: 0x2e430c, Func Offset: 0x32c
	// Line 811, Address: 0x2e4310, Func Offset: 0x330
	// Line 812, Address: 0x2e4328, Func Offset: 0x348
	// Line 815, Address: 0x2e432c, Func Offset: 0x34c
	// Line 812, Address: 0x2e4334, Func Offset: 0x354
	// Line 813, Address: 0x2e4338, Func Offset: 0x358
	// Line 814, Address: 0x2e4340, Func Offset: 0x360
	// Line 815, Address: 0x2e4344, Func Offset: 0x364
	// Line 816, Address: 0x2e435c, Func Offset: 0x37c
	// Line 819, Address: 0x2e4360, Func Offset: 0x380
	// Line 816, Address: 0x2e4368, Func Offset: 0x388
	// Line 817, Address: 0x2e436c, Func Offset: 0x38c
	// Line 818, Address: 0x2e4374, Func Offset: 0x394
	// Line 819, Address: 0x2e4378, Func Offset: 0x398
	// Line 820, Address: 0x2e4390, Func Offset: 0x3b0
	// Line 823, Address: 0x2e4394, Func Offset: 0x3b4
	// Line 820, Address: 0x2e439c, Func Offset: 0x3bc
	// Line 821, Address: 0x2e43a0, Func Offset: 0x3c0
	// Line 822, Address: 0x2e43a8, Func Offset: 0x3c8
	// Line 823, Address: 0x2e43ac, Func Offset: 0x3cc
	// Line 824, Address: 0x2e43c4, Func Offset: 0x3e4
	// Line 827, Address: 0x2e43c8, Func Offset: 0x3e8
	// Line 824, Address: 0x2e43d0, Func Offset: 0x3f0
	// Line 825, Address: 0x2e43d4, Func Offset: 0x3f4
	// Line 826, Address: 0x2e43dc, Func Offset: 0x3fc
	// Line 827, Address: 0x2e43e0, Func Offset: 0x400
	// Line 828, Address: 0x2e43f8, Func Offset: 0x418
	// Line 831, Address: 0x2e43fc, Func Offset: 0x41c
	// Line 828, Address: 0x2e4404, Func Offset: 0x424
	// Line 829, Address: 0x2e4408, Func Offset: 0x428
	// Line 830, Address: 0x2e4410, Func Offset: 0x430
	// Line 831, Address: 0x2e4414, Func Offset: 0x434
	// Line 834, Address: 0x2e4428, Func Offset: 0x448
	// Func End, Address: 0x2e4450, Func Offset: 0x470
}

// 
// Start address: 0x2e4450
int njCollisionCheckBC(_anon3* pBox, _anon2* pCapsule)
{
	unsigned int ulCnt;
	float fMaxZ;
	float fMinZ;
	float fMaxY;
	float fMinY;
	float fMaxX;
	float fMinX;
	float fR;
	float fZ2;
	float fY2;
	float fX2;
	float fZ1;
	float fY1;
	float fX1;
	_anon1 Line;
	_anon2 Capsule;
	unsigned int ulVertex[4][6];
	_anon0 Normal[6];
	// Line 855, Address: 0x2e4450, Func Offset: 0
	// Line 882, Address: 0x2e448c, Func Offset: 0x3c
	// Line 885, Address: 0x2e4490, Func Offset: 0x40
	// Line 883, Address: 0x2e4494, Func Offset: 0x44
	// Line 884, Address: 0x2e4498, Func Offset: 0x48
	// Line 886, Address: 0x2e449c, Func Offset: 0x4c
	// Line 887, Address: 0x2e44a0, Func Offset: 0x50
	// Line 888, Address: 0x2e44a4, Func Offset: 0x54
	// Line 892, Address: 0x2e44a8, Func Offset: 0x58
	// Line 893, Address: 0x2e44c4, Func Offset: 0x74
	// Line 894, Address: 0x2e44cc, Func Offset: 0x7c
	// Line 895, Address: 0x2e44e8, Func Offset: 0x98
	// Line 896, Address: 0x2e44f0, Func Offset: 0xa0
	// Line 897, Address: 0x2e450c, Func Offset: 0xbc
	// Line 898, Address: 0x2e4514, Func Offset: 0xc4
	// Line 900, Address: 0x2e458c, Func Offset: 0x13c
	// Line 904, Address: 0x2e4598, Func Offset: 0x148
	// Line 923, Address: 0x2e46d0, Func Offset: 0x280
	// Line 926, Address: 0x2e46dc, Func Offset: 0x28c
	// Line 945, Address: 0x2e4810, Func Offset: 0x3c0
	// Line 950, Address: 0x2e481c, Func Offset: 0x3cc
	// Line 951, Address: 0x2e4820, Func Offset: 0x3d0
	// Line 952, Address: 0x2e4824, Func Offset: 0x3d4
	// Line 953, Address: 0x2e4828, Func Offset: 0x3d8
	// Line 954, Address: 0x2e482c, Func Offset: 0x3dc
	// Line 951, Address: 0x2e4830, Func Offset: 0x3e0
	// Line 952, Address: 0x2e4834, Func Offset: 0x3e4
	// Line 955, Address: 0x2e4838, Func Offset: 0x3e8
	// Line 956, Address: 0x2e483c, Func Offset: 0x3ec
	// Line 957, Address: 0x2e4840, Func Offset: 0x3f0
	// Line 952, Address: 0x2e4844, Func Offset: 0x3f4
	// Line 953, Address: 0x2e4848, Func Offset: 0x3f8
	// Line 957, Address: 0x2e484c, Func Offset: 0x3fc
	// Line 953, Address: 0x2e4850, Func Offset: 0x400
	// Line 954, Address: 0x2e4854, Func Offset: 0x404
	// Line 955, Address: 0x2e485c, Func Offset: 0x40c
	// Line 956, Address: 0x2e4864, Func Offset: 0x414
	// Line 957, Address: 0x2e4868, Func Offset: 0x418
	// Line 958, Address: 0x2e4880, Func Offset: 0x430
	// Line 961, Address: 0x2e4884, Func Offset: 0x434
	// Line 958, Address: 0x2e488c, Func Offset: 0x43c
	// Line 959, Address: 0x2e4890, Func Offset: 0x440
	// Line 960, Address: 0x2e4898, Func Offset: 0x448
	// Line 961, Address: 0x2e489c, Func Offset: 0x44c
	// Line 962, Address: 0x2e48b4, Func Offset: 0x464
	// Line 965, Address: 0x2e48b8, Func Offset: 0x468
	// Line 962, Address: 0x2e48c0, Func Offset: 0x470
	// Line 963, Address: 0x2e48c4, Func Offset: 0x474
	// Line 964, Address: 0x2e48cc, Func Offset: 0x47c
	// Line 965, Address: 0x2e48d0, Func Offset: 0x480
	// Line 966, Address: 0x2e48e8, Func Offset: 0x498
	// Line 969, Address: 0x2e48ec, Func Offset: 0x49c
	// Line 966, Address: 0x2e48f4, Func Offset: 0x4a4
	// Line 967, Address: 0x2e48f8, Func Offset: 0x4a8
	// Line 968, Address: 0x2e4900, Func Offset: 0x4b0
	// Line 969, Address: 0x2e4904, Func Offset: 0x4b4
	// Line 970, Address: 0x2e491c, Func Offset: 0x4cc
	// Line 973, Address: 0x2e4920, Func Offset: 0x4d0
	// Line 970, Address: 0x2e4928, Func Offset: 0x4d8
	// Line 971, Address: 0x2e492c, Func Offset: 0x4dc
	// Line 972, Address: 0x2e4934, Func Offset: 0x4e4
	// Line 973, Address: 0x2e4938, Func Offset: 0x4e8
	// Line 974, Address: 0x2e4950, Func Offset: 0x500
	// Line 977, Address: 0x2e4954, Func Offset: 0x504
	// Line 974, Address: 0x2e495c, Func Offset: 0x50c
	// Line 975, Address: 0x2e4960, Func Offset: 0x510
	// Line 976, Address: 0x2e4968, Func Offset: 0x518
	// Line 977, Address: 0x2e496c, Func Offset: 0x51c
	// Line 978, Address: 0x2e4984, Func Offset: 0x534
	// Line 981, Address: 0x2e4988, Func Offset: 0x538
	// Line 978, Address: 0x2e4990, Func Offset: 0x540
	// Line 979, Address: 0x2e4994, Func Offset: 0x544
	// Line 980, Address: 0x2e499c, Func Offset: 0x54c
	// Line 981, Address: 0x2e49a0, Func Offset: 0x550
	// Line 982, Address: 0x2e49b8, Func Offset: 0x568
	// Line 985, Address: 0x2e49bc, Func Offset: 0x56c
	// Line 982, Address: 0x2e49c4, Func Offset: 0x574
	// Line 983, Address: 0x2e49c8, Func Offset: 0x578
	// Line 984, Address: 0x2e49d0, Func Offset: 0x580
	// Line 985, Address: 0x2e49d4, Func Offset: 0x584
	// Line 986, Address: 0x2e49ec, Func Offset: 0x59c
	// Line 989, Address: 0x2e49f0, Func Offset: 0x5a0
	// Line 986, Address: 0x2e49f8, Func Offset: 0x5a8
	// Line 987, Address: 0x2e49fc, Func Offset: 0x5ac
	// Line 988, Address: 0x2e4a04, Func Offset: 0x5b4
	// Line 989, Address: 0x2e4a08, Func Offset: 0x5b8
	// Line 990, Address: 0x2e4a20, Func Offset: 0x5d0
	// Line 993, Address: 0x2e4a24, Func Offset: 0x5d4
	// Line 990, Address: 0x2e4a2c, Func Offset: 0x5dc
	// Line 991, Address: 0x2e4a30, Func Offset: 0x5e0
	// Line 992, Address: 0x2e4a38, Func Offset: 0x5e8
	// Line 993, Address: 0x2e4a3c, Func Offset: 0x5ec
	// Line 994, Address: 0x2e4a54, Func Offset: 0x604
	// Line 997, Address: 0x2e4a58, Func Offset: 0x608
	// Line 994, Address: 0x2e4a60, Func Offset: 0x610
	// Line 995, Address: 0x2e4a64, Func Offset: 0x614
	// Line 996, Address: 0x2e4a6c, Func Offset: 0x61c
	// Line 997, Address: 0x2e4a70, Func Offset: 0x620
	// Line 998, Address: 0x2e4a88, Func Offset: 0x638
	// Line 1001, Address: 0x2e4a8c, Func Offset: 0x63c
	// Line 998, Address: 0x2e4a94, Func Offset: 0x644
	// Line 999, Address: 0x2e4a98, Func Offset: 0x648
	// Line 1000, Address: 0x2e4aa0, Func Offset: 0x650
	// Line 1001, Address: 0x2e4aa4, Func Offset: 0x654
	// Line 1008, Address: 0x2e4abc, Func Offset: 0x66c
	// Line 1005, Address: 0x2e4ac0, Func Offset: 0x670
	// Line 1006, Address: 0x2e4ac4, Func Offset: 0x674
	// Line 1007, Address: 0x2e4ac8, Func Offset: 0x678
	// Line 1008, Address: 0x2e4acc, Func Offset: 0x67c
	// Line 1009, Address: 0x2e4ad0, Func Offset: 0x680
	// Line 1010, Address: 0x2e4ae0, Func Offset: 0x690
	// Line 1011, Address: 0x2e4aec, Func Offset: 0x69c
	// Line 1010, Address: 0x2e4af0, Func Offset: 0x6a0
	// Line 1014, Address: 0x2e4af4, Func Offset: 0x6a4
	// Line 1016, Address: 0x2e4b58, Func Offset: 0x708
	// Line 1018, Address: 0x2e4b60, Func Offset: 0x710
	// Line 1016, Address: 0x2e4b64, Func Offset: 0x714
	// Line 1018, Address: 0x2e4b68, Func Offset: 0x718
	// Line 1021, Address: 0x2e4b74, Func Offset: 0x724
	// Line 1022, Address: 0x2e4b78, Func Offset: 0x728
	// Func End, Address: 0x2e4bb8, Func Offset: 0x768
}

// 
// Start address: 0x2e4bc0
int njCheckPlane4AndLine(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPN, _anon1* pLine)
{
	float fT4;
	float fT3;
	float fT2;
	float fT1;
	float fVZ4;
	float fVY4;
	float fVX4;
	float fVZ3;
	float fVY3;
	float fVX3;
	float fVZ2;
	float fVY2;
	float fVX2;
	float fVZ1;
	float fVY1;
	float fVX1;
	// Line 1051, Address: 0x2e4bc0, Func Offset: 0
	// Line 1065, Address: 0x2e4c0c, Func Offset: 0x4c
	// Line 1066, Address: 0x2e4c10, Func Offset: 0x50
	// Line 1067, Address: 0x2e4c14, Func Offset: 0x54
	// Line 1059, Address: 0x2e4c18, Func Offset: 0x58
	// Line 1060, Address: 0x2e4c1c, Func Offset: 0x5c
	// Line 1061, Address: 0x2e4c20, Func Offset: 0x60
	// Line 1068, Address: 0x2e4c24, Func Offset: 0x64
	// Line 1062, Address: 0x2e4c28, Func Offset: 0x68
	// Line 1063, Address: 0x2e4c2c, Func Offset: 0x6c
	// Line 1064, Address: 0x2e4c30, Func Offset: 0x70
	// Line 1068, Address: 0x2e4c38, Func Offset: 0x78
	// Line 1069, Address: 0x2e4c54, Func Offset: 0x94
	// Line 1071, Address: 0x2e4c68, Func Offset: 0xa8
	// Line 1074, Address: 0x2e4c78, Func Offset: 0xb8
	// Line 1076, Address: 0x2e4ca0, Func Offset: 0xe0
	// Line 1080, Address: 0x2e4ca8, Func Offset: 0xe8
	// Line 1083, Address: 0x2e4cd8, Func Offset: 0x118
	// Line 1084, Address: 0x2e4ce0, Func Offset: 0x120
	// Line 1085, Address: 0x2e4ce4, Func Offset: 0x124
	// Line 1084, Address: 0x2e4ce8, Func Offset: 0x128
	// Line 1085, Address: 0x2e4cec, Func Offset: 0x12c
	// Line 1088, Address: 0x2e4cf0, Func Offset: 0x130
	// Line 1089, Address: 0x2e4cf4, Func Offset: 0x134
	// Line 1092, Address: 0x2e4cf8, Func Offset: 0x138
	// Line 1090, Address: 0x2e4d00, Func Offset: 0x140
	// Line 1092, Address: 0x2e4d04, Func Offset: 0x144
	// Line 1093, Address: 0x2e4d24, Func Offset: 0x164
	// Line 1094, Address: 0x2e4d28, Func Offset: 0x168
	// Line 1095, Address: 0x2e4d2c, Func Offset: 0x16c
	// Line 1093, Address: 0x2e4d30, Func Offset: 0x170
	// Line 1094, Address: 0x2e4d34, Func Offset: 0x174
	// Line 1097, Address: 0x2e4d38, Func Offset: 0x178
	// Line 1095, Address: 0x2e4d40, Func Offset: 0x180
	// Line 1097, Address: 0x2e4d44, Func Offset: 0x184
	// Line 1101, Address: 0x2e4d64, Func Offset: 0x1a4
	// Line 1104, Address: 0x2e4d68, Func Offset: 0x1a8
	// Line 1100, Address: 0x2e4d70, Func Offset: 0x1b0
	// Line 1102, Address: 0x2e4d74, Func Offset: 0x1b4
	// Line 1103, Address: 0x2e4d78, Func Offset: 0x1b8
	// Line 1104, Address: 0x2e4d84, Func Offset: 0x1c4
	// Line 1103, Address: 0x2e4d88, Func Offset: 0x1c8
	// Line 1104, Address: 0x2e4d8c, Func Offset: 0x1cc
	// Line 1105, Address: 0x2e4da4, Func Offset: 0x1e4
	// Line 1108, Address: 0x2e4dac, Func Offset: 0x1ec
	// Line 1109, Address: 0x2e4db0, Func Offset: 0x1f0
	// Line 1110, Address: 0x2e4db4, Func Offset: 0x1f4
	// Line 1112, Address: 0x2e4db8, Func Offset: 0x1f8
	// Line 1105, Address: 0x2e4dc0, Func Offset: 0x200
	// Line 1109, Address: 0x2e4dcc, Func Offset: 0x20c
	// Line 1108, Address: 0x2e4dd0, Func Offset: 0x210
	// Line 1110, Address: 0x2e4dd4, Func Offset: 0x214
	// Line 1111, Address: 0x2e4dd8, Func Offset: 0x218
	// Line 1112, Address: 0x2e4de4, Func Offset: 0x224
	// Line 1111, Address: 0x2e4de8, Func Offset: 0x228
	// Line 1112, Address: 0x2e4dec, Func Offset: 0x22c
	// Line 1113, Address: 0x2e4e04, Func Offset: 0x244
	// Line 1116, Address: 0x2e4e0c, Func Offset: 0x24c
	// Line 1117, Address: 0x2e4e10, Func Offset: 0x250
	// Line 1118, Address: 0x2e4e14, Func Offset: 0x254
	// Line 1120, Address: 0x2e4e18, Func Offset: 0x258
	// Line 1113, Address: 0x2e4e20, Func Offset: 0x260
	// Line 1117, Address: 0x2e4e2c, Func Offset: 0x26c
	// Line 1116, Address: 0x2e4e30, Func Offset: 0x270
	// Line 1118, Address: 0x2e4e34, Func Offset: 0x274
	// Line 1119, Address: 0x2e4e38, Func Offset: 0x278
	// Line 1120, Address: 0x2e4e44, Func Offset: 0x284
	// Line 1119, Address: 0x2e4e48, Func Offset: 0x288
	// Line 1120, Address: 0x2e4e4c, Func Offset: 0x28c
	// Line 1121, Address: 0x2e4e64, Func Offset: 0x2a4
	// Line 1124, Address: 0x2e4e6c, Func Offset: 0x2ac
	// Line 1125, Address: 0x2e4e70, Func Offset: 0x2b0
	// Line 1126, Address: 0x2e4e74, Func Offset: 0x2b4
	// Line 1128, Address: 0x2e4e78, Func Offset: 0x2b8
	// Line 1121, Address: 0x2e4e80, Func Offset: 0x2c0
	// Line 1125, Address: 0x2e4e8c, Func Offset: 0x2cc
	// Line 1124, Address: 0x2e4e90, Func Offset: 0x2d0
	// Line 1126, Address: 0x2e4e94, Func Offset: 0x2d4
	// Line 1127, Address: 0x2e4e98, Func Offset: 0x2d8
	// Line 1128, Address: 0x2e4ea4, Func Offset: 0x2e4
	// Line 1127, Address: 0x2e4ea8, Func Offset: 0x2e8
	// Line 1128, Address: 0x2e4eac, Func Offset: 0x2ec
	// Line 1129, Address: 0x2e4ec4, Func Offset: 0x304
	// Line 1133, Address: 0x2e4ed0, Func Offset: 0x310
	// Line 1129, Address: 0x2e4ed4, Func Offset: 0x314
	// Line 1132, Address: 0x2e4edc, Func Offset: 0x31c
	// Line 1133, Address: 0x2e4ee8, Func Offset: 0x328
	// Line 1132, Address: 0x2e4eec, Func Offset: 0x32c
	// Line 1133, Address: 0x2e4ef0, Func Offset: 0x330
	// Line 1134, Address: 0x2e4f28, Func Offset: 0x368
	// Line 1135, Address: 0x2e4f38, Func Offset: 0x378
	// Line 1136, Address: 0x2e4f64, Func Offset: 0x3a4
	// Line 1137, Address: 0x2e4f74, Func Offset: 0x3b4
	// Line 1138, Address: 0x2e4fa0, Func Offset: 0x3e0
	// Line 1139, Address: 0x2e4fb0, Func Offset: 0x3f0
	// Line 1144, Address: 0x2e4fdc, Func Offset: 0x41c
	// Line 1151, Address: 0x2e5034, Func Offset: 0x474
	// Func End, Address: 0x2e5084, Func Offset: 0x4c4
}

// 
// Start address: 0x2e5090
int njCollisionCheckBC2(_anon3* pBox, _anon2* pCapsule)
{
	unsigned int ulCnt;
	float fR;
	float fZ2;
	float fY2;
	float fX2;
	float fZ1;
	float fY1;
	float fX1;
	_anon0 Cross;
	_anon1 Plane;
	_anon1 Line;
	_anon2 Capsule;
	unsigned int ulVertex[4][6];
	_anon0 Normal[6];
	// Line 1172, Address: 0x2e5090, Func Offset: 0
	// Line 1199, Address: 0x2e50d0, Func Offset: 0x40
	// Line 1200, Address: 0x2e50d4, Func Offset: 0x44
	// Line 1201, Address: 0x2e50d8, Func Offset: 0x48
	// Line 1202, Address: 0x2e50dc, Func Offset: 0x4c
	// Line 1203, Address: 0x2e50e0, Func Offset: 0x50
	// Line 1204, Address: 0x2e50e4, Func Offset: 0x54
	// Line 1205, Address: 0x2e50e8, Func Offset: 0x58
	// Line 1213, Address: 0x2e50f0, Func Offset: 0x60
	// Line 1214, Address: 0x2e50f4, Func Offset: 0x64
	// Line 1211, Address: 0x2e50f8, Func Offset: 0x68
	// Line 1212, Address: 0x2e50fc, Func Offset: 0x6c
	// Line 1215, Address: 0x2e5100, Func Offset: 0x70
	// Line 1216, Address: 0x2e5104, Func Offset: 0x74
	// Line 1217, Address: 0x2e5108, Func Offset: 0x78
	// Line 1212, Address: 0x2e510c, Func Offset: 0x7c
	// Line 1213, Address: 0x2e5110, Func Offset: 0x80
	// Line 1218, Address: 0x2e5118, Func Offset: 0x88
	// Line 1213, Address: 0x2e511c, Func Offset: 0x8c
	// Line 1214, Address: 0x2e5120, Func Offset: 0x90
	// Line 1215, Address: 0x2e5128, Func Offset: 0x98
	// Line 1216, Address: 0x2e5130, Func Offset: 0xa0
	// Line 1217, Address: 0x2e5138, Func Offset: 0xa8
	// Line 1218, Address: 0x2e5140, Func Offset: 0xb0
	// Line 1219, Address: 0x2e5158, Func Offset: 0xc8
	// Line 1222, Address: 0x2e515c, Func Offset: 0xcc
	// Line 1219, Address: 0x2e5164, Func Offset: 0xd4
	// Line 1220, Address: 0x2e5168, Func Offset: 0xd8
	// Line 1221, Address: 0x2e5170, Func Offset: 0xe0
	// Line 1222, Address: 0x2e5174, Func Offset: 0xe4
	// Line 1223, Address: 0x2e518c, Func Offset: 0xfc
	// Line 1226, Address: 0x2e5190, Func Offset: 0x100
	// Line 1223, Address: 0x2e5198, Func Offset: 0x108
	// Line 1224, Address: 0x2e519c, Func Offset: 0x10c
	// Line 1225, Address: 0x2e51a4, Func Offset: 0x114
	// Line 1226, Address: 0x2e51a8, Func Offset: 0x118
	// Line 1227, Address: 0x2e51c0, Func Offset: 0x130
	// Line 1230, Address: 0x2e51c4, Func Offset: 0x134
	// Line 1227, Address: 0x2e51cc, Func Offset: 0x13c
	// Line 1228, Address: 0x2e51d0, Func Offset: 0x140
	// Line 1229, Address: 0x2e51d8, Func Offset: 0x148
	// Line 1230, Address: 0x2e51dc, Func Offset: 0x14c
	// Line 1231, Address: 0x2e51f4, Func Offset: 0x164
	// Line 1234, Address: 0x2e51f8, Func Offset: 0x168
	// Line 1231, Address: 0x2e5200, Func Offset: 0x170
	// Line 1232, Address: 0x2e5204, Func Offset: 0x174
	// Line 1233, Address: 0x2e520c, Func Offset: 0x17c
	// Line 1234, Address: 0x2e5210, Func Offset: 0x180
	// Line 1235, Address: 0x2e5228, Func Offset: 0x198
	// Line 1238, Address: 0x2e522c, Func Offset: 0x19c
	// Line 1235, Address: 0x2e5234, Func Offset: 0x1a4
	// Line 1236, Address: 0x2e5238, Func Offset: 0x1a8
	// Line 1237, Address: 0x2e5240, Func Offset: 0x1b0
	// Line 1238, Address: 0x2e5244, Func Offset: 0x1b4
	// Line 1239, Address: 0x2e525c, Func Offset: 0x1cc
	// Line 1242, Address: 0x2e5260, Func Offset: 0x1d0
	// Line 1239, Address: 0x2e5268, Func Offset: 0x1d8
	// Line 1240, Address: 0x2e526c, Func Offset: 0x1dc
	// Line 1241, Address: 0x2e5274, Func Offset: 0x1e4
	// Line 1242, Address: 0x2e5278, Func Offset: 0x1e8
	// Line 1243, Address: 0x2e5290, Func Offset: 0x200
	// Line 1246, Address: 0x2e5294, Func Offset: 0x204
	// Line 1243, Address: 0x2e529c, Func Offset: 0x20c
	// Line 1244, Address: 0x2e52a0, Func Offset: 0x210
	// Line 1245, Address: 0x2e52a8, Func Offset: 0x218
	// Line 1246, Address: 0x2e52ac, Func Offset: 0x21c
	// Line 1247, Address: 0x2e52c4, Func Offset: 0x234
	// Line 1250, Address: 0x2e52c8, Func Offset: 0x238
	// Line 1247, Address: 0x2e52d0, Func Offset: 0x240
	// Line 1248, Address: 0x2e52d4, Func Offset: 0x244
	// Line 1249, Address: 0x2e52dc, Func Offset: 0x24c
	// Line 1250, Address: 0x2e52e0, Func Offset: 0x250
	// Line 1251, Address: 0x2e52f8, Func Offset: 0x268
	// Line 1254, Address: 0x2e52fc, Func Offset: 0x26c
	// Line 1251, Address: 0x2e5304, Func Offset: 0x274
	// Line 1252, Address: 0x2e5308, Func Offset: 0x278
	// Line 1253, Address: 0x2e5310, Func Offset: 0x280
	// Line 1254, Address: 0x2e5314, Func Offset: 0x284
	// Line 1255, Address: 0x2e532c, Func Offset: 0x29c
	// Line 1258, Address: 0x2e5330, Func Offset: 0x2a0
	// Line 1255, Address: 0x2e5338, Func Offset: 0x2a8
	// Line 1256, Address: 0x2e533c, Func Offset: 0x2ac
	// Line 1257, Address: 0x2e5344, Func Offset: 0x2b4
	// Line 1258, Address: 0x2e5348, Func Offset: 0x2b8
	// Line 1259, Address: 0x2e5360, Func Offset: 0x2d0
	// Line 1262, Address: 0x2e5364, Func Offset: 0x2d4
	// Line 1259, Address: 0x2e536c, Func Offset: 0x2dc
	// Line 1260, Address: 0x2e5370, Func Offset: 0x2e0
	// Line 1261, Address: 0x2e5378, Func Offset: 0x2e8
	// Line 1262, Address: 0x2e537c, Func Offset: 0x2ec
	// Line 1266, Address: 0x2e5394, Func Offset: 0x304
	// Line 1267, Address: 0x2e53a0, Func Offset: 0x310
	// Line 1266, Address: 0x2e53a4, Func Offset: 0x314
	// Line 1267, Address: 0x2e53ac, Func Offset: 0x31c
	// Line 1266, Address: 0x2e53b8, Func Offset: 0x328
	// Line 1268, Address: 0x2e53c0, Func Offset: 0x330
	// Line 1266, Address: 0x2e53cc, Func Offset: 0x33c
	// Line 1267, Address: 0x2e53d0, Func Offset: 0x340
	// Line 1268, Address: 0x2e53ec, Func Offset: 0x35c
	// Line 1270, Address: 0x2e5404, Func Offset: 0x374
	// Line 1272, Address: 0x2e542c, Func Offset: 0x39c
	// Line 1273, Address: 0x2e5430, Func Offset: 0x3a0
	// Line 1274, Address: 0x2e5434, Func Offset: 0x3a4
	// Line 1272, Address: 0x2e543c, Func Offset: 0x3ac
	// Line 1274, Address: 0x2e5444, Func Offset: 0x3b4
	// Line 1272, Address: 0x2e5448, Func Offset: 0x3b8
	// Line 1273, Address: 0x2e5454, Func Offset: 0x3c4
	// Line 1274, Address: 0x2e5470, Func Offset: 0x3e0
	// Line 1276, Address: 0x2e5488, Func Offset: 0x3f8
	// Line 1278, Address: 0x2e54b0, Func Offset: 0x420
	// Line 1279, Address: 0x2e54b4, Func Offset: 0x424
	// Line 1280, Address: 0x2e54b8, Func Offset: 0x428
	// Line 1278, Address: 0x2e54c0, Func Offset: 0x430
	// Line 1280, Address: 0x2e54c8, Func Offset: 0x438
	// Line 1278, Address: 0x2e54cc, Func Offset: 0x43c
	// Line 1279, Address: 0x2e54d8, Func Offset: 0x448
	// Line 1280, Address: 0x2e54f4, Func Offset: 0x464
	// Line 1282, Address: 0x2e550c, Func Offset: 0x47c
	// Line 1284, Address: 0x2e5534, Func Offset: 0x4a4
	// Line 1285, Address: 0x2e5538, Func Offset: 0x4a8
	// Line 1286, Address: 0x2e553c, Func Offset: 0x4ac
	// Line 1284, Address: 0x2e5544, Func Offset: 0x4b4
	// Line 1286, Address: 0x2e554c, Func Offset: 0x4bc
	// Line 1284, Address: 0x2e5550, Func Offset: 0x4c0
	// Line 1285, Address: 0x2e555c, Func Offset: 0x4cc
	// Line 1286, Address: 0x2e5578, Func Offset: 0x4e8
	// Line 1288, Address: 0x2e5590, Func Offset: 0x500
	// Line 1290, Address: 0x2e55b8, Func Offset: 0x528
	// Line 1291, Address: 0x2e55bc, Func Offset: 0x52c
	// Line 1292, Address: 0x2e55c0, Func Offset: 0x530
	// Line 1290, Address: 0x2e55c8, Func Offset: 0x538
	// Line 1292, Address: 0x2e55d0, Func Offset: 0x540
	// Line 1290, Address: 0x2e55d4, Func Offset: 0x544
	// Line 1291, Address: 0x2e55e0, Func Offset: 0x550
	// Line 1292, Address: 0x2e55fc, Func Offset: 0x56c
	// Line 1294, Address: 0x2e5614, Func Offset: 0x584
	// Line 1296, Address: 0x2e563c, Func Offset: 0x5ac
	// Line 1297, Address: 0x2e5640, Func Offset: 0x5b0
	// Line 1298, Address: 0x2e5644, Func Offset: 0x5b4
	// Line 1296, Address: 0x2e564c, Func Offset: 0x5bc
	// Line 1298, Address: 0x2e5654, Func Offset: 0x5c4
	// Line 1296, Address: 0x2e5658, Func Offset: 0x5c8
	// Line 1297, Address: 0x2e5664, Func Offset: 0x5d4
	// Line 1298, Address: 0x2e5680, Func Offset: 0x5f0
	// Line 1300, Address: 0x2e5698, Func Offset: 0x608
	// Line 1304, Address: 0x2e56c0, Func Offset: 0x630
	// Line 1305, Address: 0x2e56c4, Func Offset: 0x634
	// Line 1306, Address: 0x2e56c8, Func Offset: 0x638
	// Line 1304, Address: 0x2e56d0, Func Offset: 0x640
	// Line 1306, Address: 0x2e56d8, Func Offset: 0x648
	// Line 1304, Address: 0x2e56dc, Func Offset: 0x64c
	// Line 1305, Address: 0x2e56e8, Func Offset: 0x658
	// Line 1306, Address: 0x2e5704, Func Offset: 0x674
	// Line 1308, Address: 0x2e571c, Func Offset: 0x68c
	// Line 1310, Address: 0x2e5744, Func Offset: 0x6b4
	// Line 1311, Address: 0x2e5748, Func Offset: 0x6b8
	// Line 1312, Address: 0x2e574c, Func Offset: 0x6bc
	// Line 1310, Address: 0x2e5754, Func Offset: 0x6c4
	// Line 1312, Address: 0x2e575c, Func Offset: 0x6cc
	// Line 1310, Address: 0x2e5760, Func Offset: 0x6d0
	// Line 1311, Address: 0x2e576c, Func Offset: 0x6dc
	// Line 1312, Address: 0x2e5788, Func Offset: 0x6f8
	// Line 1314, Address: 0x2e57a0, Func Offset: 0x710
	// Line 1316, Address: 0x2e57c8, Func Offset: 0x738
	// Line 1317, Address: 0x2e57cc, Func Offset: 0x73c
	// Line 1318, Address: 0x2e57d0, Func Offset: 0x740
	// Line 1316, Address: 0x2e57d8, Func Offset: 0x748
	// Line 1318, Address: 0x2e57e0, Func Offset: 0x750
	// Line 1316, Address: 0x2e57e4, Func Offset: 0x754
	// Line 1317, Address: 0x2e57f0, Func Offset: 0x760
	// Line 1318, Address: 0x2e580c, Func Offset: 0x77c
	// Line 1320, Address: 0x2e5824, Func Offset: 0x794
	// Line 1322, Address: 0x2e584c, Func Offset: 0x7bc
	// Line 1323, Address: 0x2e5850, Func Offset: 0x7c0
	// Line 1324, Address: 0x2e5854, Func Offset: 0x7c4
	// Line 1322, Address: 0x2e585c, Func Offset: 0x7cc
	// Line 1324, Address: 0x2e5864, Func Offset: 0x7d4
	// Line 1322, Address: 0x2e5868, Func Offset: 0x7d8
	// Line 1323, Address: 0x2e5874, Func Offset: 0x7e4
	// Line 1324, Address: 0x2e5890, Func Offset: 0x800
	// Line 1326, Address: 0x2e58a8, Func Offset: 0x818
	// Line 1328, Address: 0x2e58d0, Func Offset: 0x840
	// Line 1329, Address: 0x2e58d4, Func Offset: 0x844
	// Line 1330, Address: 0x2e58d8, Func Offset: 0x848
	// Line 1328, Address: 0x2e58e0, Func Offset: 0x850
	// Line 1330, Address: 0x2e58e8, Func Offset: 0x858
	// Line 1328, Address: 0x2e58ec, Func Offset: 0x85c
	// Line 1329, Address: 0x2e58f8, Func Offset: 0x868
	// Line 1330, Address: 0x2e5914, Func Offset: 0x884
	// Line 1332, Address: 0x2e592c, Func Offset: 0x89c
	// Line 1334, Address: 0x2e5954, Func Offset: 0x8c4
	// Line 1335, Address: 0x2e5958, Func Offset: 0x8c8
	// Line 1336, Address: 0x2e595c, Func Offset: 0x8cc
	// Line 1334, Address: 0x2e5964, Func Offset: 0x8d4
	// Line 1336, Address: 0x2e596c, Func Offset: 0x8dc
	// Line 1334, Address: 0x2e5970, Func Offset: 0x8e0
	// Line 1335, Address: 0x2e597c, Func Offset: 0x8ec
	// Line 1336, Address: 0x2e5998, Func Offset: 0x908
	// Line 1338, Address: 0x2e59b0, Func Offset: 0x920
	// Line 1347, Address: 0x2e59d8, Func Offset: 0x948
	// Line 1344, Address: 0x2e59dc, Func Offset: 0x94c
	// Line 1345, Address: 0x2e59e0, Func Offset: 0x950
	// Line 1346, Address: 0x2e59e4, Func Offset: 0x954
	// Line 1347, Address: 0x2e59e8, Func Offset: 0x958
	// Line 1348, Address: 0x2e59ec, Func Offset: 0x95c
	// Line 1349, Address: 0x2e59fc, Func Offset: 0x96c
	// Line 1350, Address: 0x2e5a08, Func Offset: 0x978
	// Line 1349, Address: 0x2e5a0c, Func Offset: 0x97c
	// Line 1353, Address: 0x2e5a10, Func Offset: 0x980
	// Line 1355, Address: 0x2e5a74, Func Offset: 0x9e4
	// Line 1357, Address: 0x2e5a7c, Func Offset: 0x9ec
	// Line 1355, Address: 0x2e5a80, Func Offset: 0x9f0
	// Line 1357, Address: 0x2e5a84, Func Offset: 0x9f4
	// Line 1360, Address: 0x2e5a90, Func Offset: 0xa00
	// Line 1361, Address: 0x2e5a94, Func Offset: 0xa04
	// Func End, Address: 0x2e5ad8, Func Offset: 0xa48
}

// 
// Start address: 0x2e5ae0
int njCheckPlane4IncludePoint(_anon0* pP1, _anon0* pP2, _anon0* pP3, _anon0* pP4, _anon0* pPC)
{
	float fT4;
	float fT3;
	float fT2;
	float fT1;
	float fVZ4;
	float fVY4;
	float fVX4;
	float fVZ3;
	float fVY3;
	float fVX3;
	float fVZ2;
	float fVY2;
	float fVX2;
	float fVZ1;
	float fVY1;
	float fVX1;
	// Line 1388, Address: 0x2e5ae0, Func Offset: 0
	// Line 1397, Address: 0x2e5b24, Func Offset: 0x44
	// Line 1403, Address: 0x2e5b28, Func Offset: 0x48
	// Line 1398, Address: 0x2e5b2c, Func Offset: 0x4c
	// Line 1404, Address: 0x2e5b30, Func Offset: 0x50
	// Line 1399, Address: 0x2e5b34, Func Offset: 0x54
	// Line 1405, Address: 0x2e5b38, Func Offset: 0x58
	// Line 1407, Address: 0x2e5b3c, Func Offset: 0x5c
	// Line 1403, Address: 0x2e5b40, Func Offset: 0x60
	// Line 1407, Address: 0x2e5b44, Func Offset: 0x64
	// Line 1404, Address: 0x2e5b50, Func Offset: 0x70
	// Line 1405, Address: 0x2e5b54, Func Offset: 0x74
	// Line 1406, Address: 0x2e5b58, Func Offset: 0x78
	// Line 1407, Address: 0x2e5b64, Func Offset: 0x84
	// Line 1406, Address: 0x2e5b68, Func Offset: 0x88
	// Line 1407, Address: 0x2e5b6c, Func Offset: 0x8c
	// Line 1408, Address: 0x2e5b84, Func Offset: 0xa4
	// Line 1411, Address: 0x2e5b8c, Func Offset: 0xac
	// Line 1412, Address: 0x2e5b90, Func Offset: 0xb0
	// Line 1413, Address: 0x2e5b94, Func Offset: 0xb4
	// Line 1415, Address: 0x2e5b98, Func Offset: 0xb8
	// Line 1408, Address: 0x2e5ba0, Func Offset: 0xc0
	// Line 1412, Address: 0x2e5bac, Func Offset: 0xcc
	// Line 1411, Address: 0x2e5bb0, Func Offset: 0xd0
	// Line 1413, Address: 0x2e5bb4, Func Offset: 0xd4
	// Line 1414, Address: 0x2e5bb8, Func Offset: 0xd8
	// Line 1415, Address: 0x2e5bc4, Func Offset: 0xe4
	// Line 1414, Address: 0x2e5bc8, Func Offset: 0xe8
	// Line 1415, Address: 0x2e5bcc, Func Offset: 0xec
	// Line 1416, Address: 0x2e5be4, Func Offset: 0x104
	// Line 1419, Address: 0x2e5bec, Func Offset: 0x10c
	// Line 1420, Address: 0x2e5bf0, Func Offset: 0x110
	// Line 1421, Address: 0x2e5bf4, Func Offset: 0x114
	// Line 1423, Address: 0x2e5bf8, Func Offset: 0x118
	// Line 1416, Address: 0x2e5c00, Func Offset: 0x120
	// Line 1420, Address: 0x2e5c0c, Func Offset: 0x12c
	// Line 1419, Address: 0x2e5c10, Func Offset: 0x130
	// Line 1421, Address: 0x2e5c14, Func Offset: 0x134
	// Line 1422, Address: 0x2e5c18, Func Offset: 0x138
	// Line 1423, Address: 0x2e5c24, Func Offset: 0x144
	// Line 1422, Address: 0x2e5c28, Func Offset: 0x148
	// Line 1423, Address: 0x2e5c2c, Func Offset: 0x14c
	// Line 1424, Address: 0x2e5c44, Func Offset: 0x164
	// Line 1427, Address: 0x2e5c4c, Func Offset: 0x16c
	// Line 1428, Address: 0x2e5c50, Func Offset: 0x170
	// Line 1429, Address: 0x2e5c54, Func Offset: 0x174
	// Line 1431, Address: 0x2e5c58, Func Offset: 0x178
	// Line 1424, Address: 0x2e5c60, Func Offset: 0x180
	// Line 1428, Address: 0x2e5c6c, Func Offset: 0x18c
	// Line 1427, Address: 0x2e5c70, Func Offset: 0x190
	// Line 1429, Address: 0x2e5c74, Func Offset: 0x194
	// Line 1430, Address: 0x2e5c78, Func Offset: 0x198
	// Line 1431, Address: 0x2e5c84, Func Offset: 0x1a4
	// Line 1430, Address: 0x2e5c88, Func Offset: 0x1a8
	// Line 1431, Address: 0x2e5c8c, Func Offset: 0x1ac
	// Line 1432, Address: 0x2e5ca4, Func Offset: 0x1c4
	// Line 1436, Address: 0x2e5cb0, Func Offset: 0x1d0
	// Line 1432, Address: 0x2e5cb4, Func Offset: 0x1d4
	// Line 1435, Address: 0x2e5cbc, Func Offset: 0x1dc
	// Line 1436, Address: 0x2e5cc8, Func Offset: 0x1e8
	// Line 1435, Address: 0x2e5ccc, Func Offset: 0x1ec
	// Line 1436, Address: 0x2e5cd0, Func Offset: 0x1f0
	// Line 1437, Address: 0x2e5d08, Func Offset: 0x228
	// Line 1438, Address: 0x2e5d18, Func Offset: 0x238
	// Line 1439, Address: 0x2e5d44, Func Offset: 0x264
	// Line 1440, Address: 0x2e5d54, Func Offset: 0x274
	// Line 1441, Address: 0x2e5d80, Func Offset: 0x2a0
	// Line 1442, Address: 0x2e5d90, Func Offset: 0x2b0
	// Line 1447, Address: 0x2e5dbc, Func Offset: 0x2dc
	// Line 1454, Address: 0x2e5e14, Func Offset: 0x334
	// Func End, Address: 0x2e5e5c, Func Offset: 0x37c
}

