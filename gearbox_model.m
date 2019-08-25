% gearbox 'model'

syms rot_speed;

constantG = lsqcurvefit(@f,[0;0],speed_1,t1);
mg1 = constantG(1);
cg1 = constantG(2);
xfit_g1 = 71:0.1:96;
yfit_g1 = f(constantG,xfit_g1);
K1 = 2.78;
line_g1 = rot_speed*mg1 + K1;


constantG2  = lsqcurvefit(@f,[0;0],speed_2,t2);
mg2 = constantG2(1);
cg2 = constantG2(2);
xfit_g2 = 103:0.1:117;
y_fit_g2 = f(constantG2,xfit_g2);
K2 = 4.07;
line_g2 = rot_speed*mg2 + K2;


constantG3 = lsqcurvefit(@f,[0;0],speed_3,t3);
mg3 = constantG3(1);
cg3 = constantG3(2);
xfit_g3 = 125:0.1:132;
y_fit_g3 = f(constantG3,xfit_g3);
K3 = 0;
line_g3 = rot_speed*mg3 + K3;

% % 
constantG4 =  lsqcurvefit(@f,[0;0],speed_4,t4);
mg4 = constantG4(1);
cg4 = constantG4(2);
xfit_g4 = 142:0.1:175;
y_fit_g4 = f(constantG4,xfit_g4);
K4 = 0;
line_g4 = rot_speed*mg4 + K4;


%x = 0:0.1:200;

 y = piecewise(71<rot_speed<96,line_g1,103<rot_speed<117,line_g2,125<rot_speed<132,line_g3,142<rot_speed<175,line_g4);
 
fplot(y,'ro');
axis([0 175   0 77]);



