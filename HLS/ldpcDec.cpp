
#include <hls_math.h>
#include <ap_int.h>
#include "ldpcDec.h"
void readData(ap_int<8> llr[N],ap_int<12> minfo[920][3072],ap_int<12> blockllr[68][3072]){
	for(int i=0;i<48;i++){
		for(int j=0;j<BL;j++){
#pragma HLS PIPELINE
			ap_int<8> s = llr[i*BL+j];
			blockllr[i][j] = s;
			parall_assign:for(int k=0;k<920;k++){
			#pragma HLS UNROLL factor=920
				if(k>=sel[i]&&k<sel[i+1])
					minfo[k][j] = s;
			}
		}
	}

}

void updateMinfo(ap_int<8> llr[N], ap_int<12> minfo[920][3072],ap_int<12> blockllr[48][3072],bool blockdout[48][3072]){

#pragma HLS ARRAY_PARTITION variable=minfo complete dim=1
#pragma HLS ARRAY_PARTITION variable=blockllr complete dim=1
#pragma HLS ARRAY_PARTITION variable=blockdout complete dim=1
	for(int i=0;i<BL;i++){
#pragma HLS DEPENDENCE variable=minfo inter false
#pragma HLS PIPELINE
		ARRAY12 a[46];
		ARRAY12 b[46];
		for(int j=0;j<48;j++){
#pragma HLS UNROLL
			for(int k=0;k<12;k++){
#pragma HLS UNROLL
				if(k<10)
					a[j].a[k] = minfo[rowPara[j][k]][(pidx[rowPara[j][k]]+i)%BL];
				else
					a[j].a[k] = 127;
			}
			b[j] = rowUpdate12(a[j]);
			for(int k=0;k<20;k++){
#pragma HLS UNROLL
				minfo[rowPara[j][k]][(pidx[rowPara[j][k]]+i)%BL] = b[j].a[k];
			}
		}
	}
	colUpdate20(blockdout[0],blockllr[0],minfo[0],minfo[1],minfo[2],minfo[3],minfo[4],minfo[5],minfo[6],minfo[7],minfo[8],minfo[9],minfo[10],minfo[11],minfo[12],minfo[13],minfo[14],minfo[15],minfo[16],minfo[17],minfo[18],minfo[19]);
	colUpdate20(blockdout[1],blockllr[1],minfo[20],minfo[21],minfo[22],minfo[23],minfo[24],minfo[25],minfo[26],minfo[27],minfo[28],minfo[29],minfo[30],minfo[31],minfo[32],minfo[33],minfo[34],minfo[35],minfo[36],minfo[37],minfo[38],minfo[39]);
	colUpdate20(blockdout[2],blockllr[2],minfo[40],minfo[41],minfo[42],minfo[43],minfo[44],minfo[45],minfo[46],minfo[47],minfo[48],minfo[49],minfo[50],minfo[51],minfo[52],minfo[53],minfo[54],minfo[55],minfo[56],minfo[57],minfo[58],minfo[59]);
	colUpdate20(blockdout[3],blockllr[3],minfo[60],minfo[61],minfo[62],minfo[63],minfo[64],minfo[65],minfo[66],minfo[67],minfo[68],minfo[69],minfo[70],minfo[71],minfo[72],minfo[73],minfo[74],minfo[75],minfo[76],minfo[77],minfo[78],minfo[79]);
	colUpdate20(blockdout[4],blockllr[4],minfo[80],minfo[81],minfo[82],minfo[83],minfo[84],minfo[85],minfo[86],minfo[87],minfo[88],minfo[89],minfo[90],minfo[91],minfo[92],minfo[93],minfo[94],minfo[95],minfo[96],minfo[97],minfo[98],minfo[99]);
	colUpdate20(blockdout[5],blockllr[5],minfo[100],minfo[101],minfo[102],minfo[103],minfo[104],minfo[105],minfo[106],minfo[107],minfo[108],minfo[109],minfo[110],minfo[111],minfo[112],minfo[113],minfo[114],minfo[115],minfo[116],minfo[117],minfo[118],minfo[119]);
	colUpdate20(blockdout[6],blockllr[6],minfo[120],minfo[121],minfo[122],minfo[123],minfo[124],minfo[125],minfo[126],minfo[127],minfo[128],minfo[129],minfo[130],minfo[131],minfo[132],minfo[133],minfo[134],minfo[135],minfo[136],minfo[137],minfo[138],minfo[139]);
	colUpdate20(blockdout[7],blockllr[7],minfo[140],minfo[141],minfo[142],minfo[143],minfo[144],minfo[145],minfo[146],minfo[147],minfo[148],minfo[149],minfo[150],minfo[151],minfo[152],minfo[153],minfo[154],minfo[155],minfo[156],minfo[157],minfo[158],minfo[159]);
	colUpdate20(blockdout[8],blockllr[8],minfo[160],minfo[161],minfo[162],minfo[163],minfo[164],minfo[165],minfo[166],minfo[167],minfo[168],minfo[169],minfo[170],minfo[171],minfo[172],minfo[173],minfo[174],minfo[175],minfo[176],minfo[177],minfo[178],minfo[179]);
	colUpdate20(blockdout[9],blockllr[9],minfo[180],minfo[181],minfo[182],minfo[183],minfo[184],minfo[185],minfo[186],minfo[187],minfo[188],minfo[189],minfo[190],minfo[191],minfo[192],minfo[193],minfo[194],minfo[195],minfo[196],minfo[197],minfo[198],minfo[199]);
	colUpdate20(blockdout[10],blockllr[10],minfo[200],minfo[201],minfo[202],minfo[203],minfo[204],minfo[205],minfo[206],minfo[207],minfo[208],minfo[209],minfo[210],minfo[211],minfo[212],minfo[213],minfo[214],minfo[215],minfo[216],minfo[217],minfo[218],minfo[219]);
	colUpdate20(blockdout[11],blockllr[11],minfo[220],minfo[221],minfo[222],minfo[223],minfo[224],minfo[225],minfo[226],minfo[227],minfo[228],minfo[229],minfo[230],minfo[231],minfo[232],minfo[233],minfo[234],minfo[235],minfo[236],minfo[237],minfo[238],minfo[239]);
	colUpdate20(blockdout[12],blockllr[12],minfo[240],minfo[241],minfo[242],minfo[243],minfo[244],minfo[245],minfo[246],minfo[247],minfo[248],minfo[249],minfo[250],minfo[251],minfo[252],minfo[253],minfo[254],minfo[255],minfo[256],minfo[257],minfo[258],minfo[259]);
	colUpdate20(blockdout[13],blockllr[13],minfo[260],minfo[261],minfo[262],minfo[263],minfo[264],minfo[265],minfo[266],minfo[267],minfo[268],minfo[269],minfo[270],minfo[271],minfo[272],minfo[273],minfo[274],minfo[275],minfo[276],minfo[277],minfo[278],minfo[279]);
	colUpdate20(blockdout[14],blockllr[14],minfo[280],minfo[281],minfo[282],minfo[283],minfo[284],minfo[285],minfo[286],minfo[287],minfo[288],minfo[289],minfo[290],minfo[291],minfo[292],minfo[293],minfo[294],minfo[295],minfo[296],minfo[297],minfo[298],minfo[299]);
	colUpdate20(blockdout[15],blockllr[15],minfo[300],minfo[301],minfo[302],minfo[303],minfo[304],minfo[305],minfo[306],minfo[307],minfo[308],minfo[309],minfo[310],minfo[311],minfo[312],minfo[313],minfo[314],minfo[315],minfo[316],minfo[317],minfo[318],minfo[319]);
	colUpdate20(blockdout[16],blockllr[16],minfo[320],minfo[321],minfo[322],minfo[323],minfo[324],minfo[325],minfo[326],minfo[327],minfo[328],minfo[329],minfo[330],minfo[331],minfo[332],minfo[333],minfo[334],minfo[335],minfo[336],minfo[337],minfo[338],minfo[339]);
	colUpdate20(blockdout[17],blockllr[17],minfo[340],minfo[341],minfo[342],minfo[343],minfo[344],minfo[345],minfo[346],minfo[347],minfo[348],minfo[349],minfo[350],minfo[351],minfo[352],minfo[353],minfo[354],minfo[355],minfo[356],minfo[357],minfo[358],minfo[359]);
	colUpdate20(blockdout[18],blockllr[18],minfo[360],minfo[361],minfo[362],minfo[363],minfo[364],minfo[365],minfo[366],minfo[367],minfo[368],minfo[369],minfo[370],minfo[371],minfo[372],minfo[373],minfo[374],minfo[375],minfo[376],minfo[377],minfo[378],minfo[379]);
	colUpdate20(blockdout[19],blockllr[19],minfo[380],minfo[381],minfo[382],minfo[383],minfo[384],minfo[385],minfo[386],minfo[387],minfo[388],minfo[389],minfo[390],minfo[391],minfo[392],minfo[393],minfo[394],minfo[395],minfo[396],minfo[397],minfo[398],minfo[399]);
	colUpdate20(blockdout[20],blockllr[20],minfo[400],minfo[401],minfo[402],minfo[403],minfo[404],minfo[405],minfo[406],minfo[407],minfo[408],minfo[409],minfo[410],minfo[411],minfo[412],minfo[413],minfo[414],minfo[415],minfo[416],minfo[417],minfo[418],minfo[419]);
	colUpdate20(blockdout[21],blockllr[21],minfo[420],minfo[421],minfo[422],minfo[423],minfo[424],minfo[425],minfo[426],minfo[427],minfo[428],minfo[429],minfo[430],minfo[431],minfo[432],minfo[433],minfo[434],minfo[435],minfo[436],minfo[437],minfo[438],minfo[439]);
	colUpdate20(blockdout[22],blockllr[22],minfo[440],minfo[441],minfo[442],minfo[443],minfo[444],minfo[445],minfo[446],minfo[447],minfo[448],minfo[449],minfo[450],minfo[451],minfo[452],minfo[453],minfo[454],minfo[455],minfo[456],minfo[457],minfo[458],minfo[459]);
	colUpdate20(blockdout[23],blockllr[23],minfo[460],minfo[461],minfo[462],minfo[463],minfo[464],minfo[465],minfo[466],minfo[467],minfo[468],minfo[469],minfo[470],minfo[471],minfo[472],minfo[473],minfo[474],minfo[475],minfo[476],minfo[477],minfo[478],minfo[479]);
	colUpdate20(blockdout[24],blockllr[24],minfo[480],minfo[481],minfo[482],minfo[483],minfo[484],minfo[485],minfo[486],minfo[487],minfo[488],minfo[489],minfo[490],minfo[491],minfo[492],minfo[493],minfo[494],minfo[495],minfo[496],minfo[497],minfo[498],minfo[499]);
	colUpdate20(blockdout[25],blockllr[25],minfo[500],minfo[501],minfo[502],minfo[503],minfo[504],minfo[505],minfo[506],minfo[507],minfo[508],minfo[509],minfo[510],minfo[511],minfo[512],minfo[513],minfo[514],minfo[515],minfo[516],minfo[517],minfo[518],minfo[519]);
	colUpdate20(blockdout[26],blockllr[26],minfo[520],minfo[521],minfo[522],minfo[523],minfo[524],minfo[525],minfo[526],minfo[527],minfo[528],minfo[529],minfo[530],minfo[531],minfo[532],minfo[533],minfo[534],minfo[535],minfo[536],minfo[537],minfo[538],minfo[539]);
	colUpdate20(blockdout[27],blockllr[27],minfo[540],minfo[541],minfo[542],minfo[543],minfo[544],minfo[545],minfo[546],minfo[547],minfo[548],minfo[549],minfo[550],minfo[551],minfo[552],minfo[553],minfo[554],minfo[555],minfo[556],minfo[557],minfo[558],minfo[559]);
	colUpdate20(blockdout[28],blockllr[28],minfo[560],minfo[561],minfo[562],minfo[563],minfo[564],minfo[565],minfo[566],minfo[567],minfo[568],minfo[569],minfo[570],minfo[571],minfo[572],minfo[573],minfo[574],minfo[575],minfo[576],minfo[577],minfo[578],minfo[579]);
	colUpdate20(blockdout[29],blockllr[29],minfo[580],minfo[581],minfo[582],minfo[583],minfo[584],minfo[585],minfo[586],minfo[587],minfo[588],minfo[589],minfo[590],minfo[591],minfo[592],minfo[593],minfo[594],minfo[595],minfo[596],minfo[597],minfo[598],minfo[599]);
	colUpdate20(blockdout[30],blockllr[30],minfo[600],minfo[601],minfo[602],minfo[603],minfo[604],minfo[605],minfo[606],minfo[607],minfo[608],minfo[609],minfo[610],minfo[611],minfo[612],minfo[613],minfo[614],minfo[615],minfo[616],minfo[617],minfo[618],minfo[619]);
	colUpdate20(blockdout[31],blockllr[31],minfo[620],minfo[621],minfo[622],minfo[623],minfo[624],minfo[625],minfo[626],minfo[627],minfo[628],minfo[629],minfo[630],minfo[631],minfo[632],minfo[633],minfo[634],minfo[635],minfo[636],minfo[637],minfo[638],minfo[639]);
	colUpdate20(blockdout[32],blockllr[32],minfo[640],minfo[641],minfo[642],minfo[643],minfo[644],minfo[645],minfo[646],minfo[647],minfo[648],minfo[649],minfo[650],minfo[651],minfo[652],minfo[653],minfo[654],minfo[655],minfo[656],minfo[657],minfo[658],minfo[659]);
	colUpdate20(blockdout[33],blockllr[33],minfo[660],minfo[661],minfo[662],minfo[663],minfo[664],minfo[665],minfo[666],minfo[667],minfo[668],minfo[669],minfo[670],minfo[671],minfo[672],minfo[673],minfo[674],minfo[675],minfo[676],minfo[677],minfo[678],minfo[679]);
	colUpdate20(blockdout[34],blockllr[34],minfo[680],minfo[681],minfo[682],minfo[683],minfo[684],minfo[685],minfo[686],minfo[687],minfo[688],minfo[689],minfo[690],minfo[691],minfo[692],minfo[693],minfo[694],minfo[695],minfo[696],minfo[697],minfo[698],minfo[699]);
	colUpdate20(blockdout[35],blockllr[35],minfo[700],minfo[701],minfo[702],minfo[703],minfo[704],minfo[705],minfo[706],minfo[707],minfo[708],minfo[709],minfo[710],minfo[711],minfo[712],minfo[713],minfo[714],minfo[715],minfo[716],minfo[717],minfo[718],minfo[719]);
	colUpdate20(blockdout[36],blockllr[36],minfo[720],minfo[721],minfo[722],minfo[723],minfo[724],minfo[725],minfo[726],minfo[727],minfo[728],minfo[729],minfo[730],minfo[731],minfo[732],minfo[733],minfo[734],minfo[735],minfo[736],minfo[737],minfo[738],minfo[739]);
	colUpdate20(blockdout[37],blockllr[37],minfo[740],minfo[741],minfo[742],minfo[743],minfo[744],minfo[745],minfo[746],minfo[747],minfo[748],minfo[749],minfo[750],minfo[751],minfo[752],minfo[753],minfo[754],minfo[755],minfo[756],minfo[757],minfo[758],minfo[759]);
	colUpdate20(blockdout[38],blockllr[38],minfo[760],minfo[761],minfo[762],minfo[763],minfo[764],minfo[765],minfo[766],minfo[767],minfo[768],minfo[769],minfo[770],minfo[771],minfo[772],minfo[773],minfo[774],minfo[775],minfo[776],minfo[777],minfo[778],minfo[779]);
	colUpdate20(blockdout[39],blockllr[39],minfo[780],minfo[781],minfo[782],minfo[783],minfo[784],minfo[785],minfo[786],minfo[787],minfo[788],minfo[789],minfo[790],minfo[791],minfo[792],minfo[793],minfo[794],minfo[795],minfo[796],minfo[797],minfo[798],minfo[799]);
	colUpdate15(blockdout[40],blockllr[40],minfo[800],minfo[801],minfo[802],minfo[803],minfo[804],minfo[805],minfo[806],minfo[807],minfo[808],minfo[809],minfo[810],minfo[811],minfo[812],minfo[813],minfo[814]);
	colUpdate15(blockdout[41],blockllr[41],minfo[815],minfo[816],minfo[817],minfo[818],minfo[819],minfo[820],minfo[821],minfo[822],minfo[823],minfo[824],minfo[825],minfo[826],minfo[827],minfo[828],minfo[829]);
	colUpdate15(blockdout[42],blockllr[42],minfo[830],minfo[831],minfo[832],minfo[833],minfo[834],minfo[835],minfo[836],minfo[837],minfo[838],minfo[839],minfo[840],minfo[841],minfo[842],minfo[843],minfo[844]);
	colUpdate15(blockdout[43],blockllr[43],minfo[845],minfo[846],minfo[847],minfo[848],minfo[849],minfo[850],minfo[851],minfo[852],minfo[853],minfo[854],minfo[855],minfo[856],minfo[857],minfo[858],minfo[859]);
	colUpdate15(blockdout[44],blockllr[44],minfo[860],minfo[861],minfo[862],minfo[863],minfo[864],minfo[865],minfo[866],minfo[867],minfo[868],minfo[869],minfo[870],minfo[871],minfo[872],minfo[873],minfo[874]);
	colUpdate15(blockdout[45],blockllr[45],minfo[875],minfo[876],minfo[877],minfo[878],minfo[879],minfo[880],minfo[881],minfo[882],minfo[883],minfo[884],minfo[885],minfo[886],minfo[887],minfo[888],minfo[889]);
	colUpdate15(blockdout[46],blockllr[46],minfo[890],minfo[891],minfo[892],minfo[893],minfo[894],minfo[895],minfo[896],minfo[897],minfo[898],minfo[899],minfo[900],minfo[901],minfo[902],minfo[903],minfo[904]);
	colUpdate15(blockdout[47],blockllr[47],minfo[905],minfo[906],minfo[907],minfo[908],minfo[909],minfo[910],minfo[911],minfo[912],minfo[913],minfo[914],minfo[915],minfo[916],minfo[917],minfo[918],minfo[919]);
}


void ldpcDec(ap_int<8> llr[N],bool output[K]){
#pragma HLS INTERFACE axis register both port=llr
#pragma HLS INTERFACE axis register both port=output
	   ap_int<12> minfo[920][3072];
	   ap_int<12> blockllr[48][3072];
	   bool blockdout[48][3072];
	   readData(llr,minfo,blockllr);
	   for(int i=0;i<ITERNUM;i++)
		   updateMinfo(llr,minfo,blockllr,blockdout);
	   int cnt = 0;
	   for(int i=0;i<16;i++){
		   for(int j=0;j<BL;j++){
#pragma HLS PIPELINE
			   output[cnt] = blockdout[i][j];
			   cnt++;
		   }
	   }

}



inline ARRAY2 compMin(ap_int<8> a,ap_int<8> b,ap_int<8> c,ap_int<8> d){
	ARRAY2 res;
	if(a<c){
		res.a1 = a;
		if(b<c)
			res.a2 = b;
		else
			res.a2 = c;
	}
	else{
		res.a1 = c;
		if(a<d)
			res.a2 = a;
		else
			res.a2 = d;
	}
	return res;
}
inline ARRAY12 rowUpdate12(ARRAY12 a){
#pragma HLS PIPELINE
#pragma HLS ARRAY_PARTITION variable=a complete dim=1
	bool mark1[12];
	ap_int<8> a1[12];
	for(int i=0;i<12;i++){
#pragma HLS UNROLL
		if(a.a[i]<0){
			mark1[i] = false;
			a1[i] =  (-a.a[i])-((-a.a[i])>>3)-((-a.a[i])>>4);
		}
		else{
			mark1[i] = true;
			a1[i] =  a.a[i] - (a.a[i]>>3) - (a.a[i]>>4);
		}
	}
	ap_int<8> a2[12];
	for(int i=0;i<6;i++){
#pragma HLS UNROLL
		if(a1[2*i]<a1[2*i+1]){
			a2[2*i] = a1[2*i];
			a2[2*i+1] = a1[2*i+1];
		}
		else{
			a2[2*i] = a1[2*i+1];
			a2[2*i+1] = a1[2*i];
		}
	}
	ARRAY2 a3[2];
	a3[0] = compMin(a2[0],a2[1],a2[2],a2[3]);
	a3[1] = compMin(a2[4],a2[5],a2[6],a2[7]);
	ARRAY2 a4[2];
	a4[0] = compMin(a3[0].a1,a3[0].a2,a3[1].a1,a3[1].a2);
	a4[1] = compMin(a2[8],a2[9],a2[10],a2[11]);
	ARRAY2 a5;
	a5 = compMin(a4[0].a1,a4[0].a2,a4[1].a1,a4[1].a2);
	bool marka = true;
	for(int i=0;i<12;i++){
#pragma HLS UNROLL
		marka = marka==mark1[i];
	}
	ARRAY12 res;
#pragma HLS ARRAY_PARTITION variable=res complete dim=1
	for(int i=0;i<12;i++){
#pragma HLS UNROLL
		if(marka==mark1[i]){
			if(a5.a1==a1[i])
				res.a[i] = a5.a2;
			else
				res.a[i] = a5.a1;
		}
		else{
			if(a5.a1==a1[i])
				res.a[i] = -a5.a2;
			else
				res.a[i] = -a5.a1;
		}
	}
	return res;
}

/*inline void colUpdate3(bool r[3072],ap_int<12> l[3072],ap_int<12> a[3072],ap_int<12> b[3072],ap_int<12> c[3072]){
	for(int i=0;i<BL;i++){
#pragma HLS PIPELINE
		ap_int<8> t[3];
		t[0] = a[i];
		t[1] = b[i];
		t[2] = c[i];
		ap_int<11> sum = l[i] + t[0] + t[1] + t[2];
		ap_int<11> s[3];
#pragma UNROLL
		for(int j=0;j<3;j++){
			s[j] = sum - t[j];
			if(s[j]>127)
				s[j] = 127;
			if(s[j]<-128)
				s[j] = -128;
		}
		a[i] = s[0];
		b[i] = s[1];
		c[i] = s[2];
		r[i] = sum<0;
	}
}*/
inline void colUpdate20(bool r[3072],ap_int<12> l[3072],ap_int<12> a[3072],ap_int<12> b[3072],ap_int<12> c[3072],ap_int<12> d[3072],ap_int<12> e[3072],ap_int<12> f[3072],ap_int<12> g[3072],ap_int<12> h[3072],ap_int<12> I[3072],
		ap_int<12> j[3072],ap_int<12> k[3072],ap_int<12> L[3072],ap_int<12> m[3072],ap_int<12> n[3072],ap_int<12> o[3072],
ap_int<12> p[3072],ap_int<12> q[3072],ap_int<12> R[3072],ap_int<12> S[3072],ap_int<12> T[3072]){
	for(int i=0;i<BL;i++){
	#pragma HLS PIPELINE
			ap_int<12> t[20];
			t[0] = a[i];
			t[1] = b[i];
			t[2] = c[i];
			t[3] = d[i];
			t[4] = e[i];
			t[5] = f[i];
			t[6] = g[i];
			t[7] = h[i];
			t[8] = I[i];
			t[9] = j[i];
			t[10] = k[i];
			t[11] = L[i];
			t[12] = m[i];
			t[13] = n[i];
			t[14] = o[i];
			t[15] = p[i];
			t[16] = q[i];
			t[17] = r[i];
			t[18] = S[i];
			t[19] = T[i];
			ap_int<15> sum = l[i] + t[0] + t[1]+ t[2] + t[3] + t[4] + t[5] +t[6]+ t[7]+ t[8]+ t[9]+ t[10]+ t[11]+ t[12]+ t[13]+ t[14]+t[15]+t[16]+t[17]+t[18]+t[19];
			ap_int<15> s[20];
	#pragma UNROLL
			for(int j=0;j<20;j++){
				s[j] = sum - t[j];
				if(s[j]>127)
					s[j] = 4095;
				if(s[j]<-4096)
					s[j] = -4096;
			}
			a[i] = s[0];
			b[i] = s[1];
			c[i] = s[2];
			d[i] = s[3];
			e[i] = s[4];
			f[i] = s[5];
			g[i] = s[6];
			h[i] = s[7];
			I[i] = s[8];
			j[i] = s[9];
			k[i] = s[10];
			L[i] = s[11];
			m[i] = s[12];
			n[i] = s[13];
			o[i] = s[14];
			p[i] = s[14];
			q[i] = s[14];
			R[i] = s[14];
			S[i] = s[14];
			T[i] = s[14];
			r[i] = sum<0;
		}
}
inline void colUpdate15(bool r[3072],ap_int<12> l[3072],ap_int<12> a[3072],ap_int<12> b[3072],ap_int<12> c[3072],ap_int<12> d[3072],ap_int<12> e[3072],ap_int<12> f[3072],ap_int<12> g[3072],ap_int<12> h[3072],ap_int<12> I[3072],
		ap_int<12> j[3072],ap_int<12> k[3072],ap_int<12> L[3072],ap_int<12> m[3072],ap_int<12> n[3072],ap_int<12> o[3072]){
	for(int i=0;i<BL;i++){
	#pragma HLS PIPELINE
			ap_int<12> t[15];
			t[0] = a[i];
			t[1] = b[i];
			t[2] = c[i];
			t[3] = d[i];
			t[4] = e[i];
			t[5] = f[i];
			t[6] = g[i];
			t[7] = h[i];
			t[8] = I[i];
			t[9] = j[i];
			t[10] = k[i];
			t[11] = L[i];
			t[12] = m[i];
			t[13] = n[i];
			t[14] = o[i];
			ap_int<15> sum = l[i] + t[0] + t[1] + t[2] + t[3] + t[4] + t[5] +  t[6]+ t[7]+ t[8]+ t[9]+ t[10]+ t[11]+ t[12]+ t[13]+ t[14];
			ap_int<15> s[15];
	#pragma UNROLL
			for(int j=0;j<15;j++){
				s[j] = sum - t[j];
				if(s[j]>4095)
					s[j] = 127;
				if(s[j]<-4096)
					s[j] = -4096;
			}
			a[i] = s[0];
			b[i] = s[1];
			c[i] = s[2];
			d[i] = s[3];
			e[i] = s[4];
			f[i] = s[5];
			g[i] = s[6];
			h[i] = s[7];
			I[i] = s[8];
			j[i] = s[9];
			k[i] = s[10];
			L[i] = s[11];
			m[i] = s[12];
			n[i] = s[13];
			o[i] = s[14];
			r[i] = sum<0;
		}
}

