%BPSK_nrldpc_sim_RM_FP.m, NR_1_1_24, Rate = 1/2, rmax = 3, MaxItrs = 20
res11 = [1.000000    200    0.005000    0.097538;

1.000000    400    0.002500    0.097538;

1.000000   600    0.001667    0.097538;

1.000000    800    0.001250    0.097538;

1.000000    1000    0.001000   0.097538;

1.000000    1500    0.000667    0.097538;

1.000000    2000    0.000500    0.097538
    ];

%BPSK_nrldpc_sim_RM_FP.m, NR_2_6_52, Rate = 1/2, rmax = 3, MaxItrs = 20
res12 = [1         0.84      0.12602           84         6553          100;
    1.5        0.335     0.037215          335        19352         1000;
    2       0.0366      0.00342          183         8892         5000;
    2.35       0.0027   0.00025644           54         2667        20000
    ];

% %nrpolar_scdecode_FP.m, K = 512, rmax = 4
% res2 = [1         0.78      0.29258           78        14980          100;
%     1.5        0.415      0.12834          415        65710         1000;
%     2       0.1172     0.029889          586        76517         5000;
%     2.5       0.0176    0.0034977           88         8954         5000;
%     3       0.0026    0.0003959           52         4054        20000
%     ];
% 
% %nrpolar_sclistdecode_FP.m, A = 500, crcL = 11, rmax = 4
% res3 = [1          0.4      0.13288           40         6644          100;
%     1.5        0.088     0.026858           88        13429         1000;
%     2       0.0072    0.0017464           36         4366         5000;
%     2.25       0.0017    0.0004962           34         4962        20000
%     ];

semilogy(res11(:,2),res11(:,4),'ro-','LineWidth',2,'MarkerSize',8)
hold on
%semilogy(res12(:,1),res12(:,2),'bd-','LineWidth',2,'MarkerSize',8)
% semilogy(res2(:,1),res2(:,2),'kx-','LineWidth',2,'MarkerSize',8)
% semilogy(res3(:,1),res3(:,2),'k*-','LineWidth',2,'MarkerSize',8)
% semilogy(res11(:,1),res11(:,3),'ro--','LineWidth',2,'MarkerSize',8)
% semilogy(res12(:,1),res12(:,3),'bd--','LineWidth',2,'MarkerSize',8)
% semilogy(res2(:,1),res2(:,3),'kx--','LineWidth',2,'MarkerSize',8)
% semilogy(res3(:,1),res3(:,3),'k*--','LineWidth',2,'MarkerSize',8)

grid on
set(gca,'FontName','Times','FontSize',16);
axis([0 200 400 600 800 1000 1500 2000])
%xlabel('E_b/N_0 (dB)','FontName','Times','FontSize',16)
xlabel('Frames','FontName','Times','FontSize',16)
%ylabel('FER','FontName','Times','FontSize',16)
ylabel('BER','FontName','Times','FontSize',16)
% title('LDPC and Polar Codes, Rate \approx 1/2, length \approx 1024','FontName','Times','FontSize',16)
% legend('LDPC, BG1','LDPC, BG2','Polar, SC','Polar, SClist4')
title('Frames vs BER','FontName','Times','FontSize',16)
legend('LDPC, BG1')
