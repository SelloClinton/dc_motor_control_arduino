% constant = lsqcurvefit(@f,[0;0],rpmP1,t_p1);
% m = constant(1);
% c = constant(2);
% xfit_p1 = 43:0.1:91;
% yfit_p1 = f(constant,xfit);
% %equation 1
% line_1 = m*rpm;

syms rpm;
%p1
constant_p1 = lsqcurvefit(@f,[0;0],rpm_p1,t_p1);
xfit_p1 = -43*rd:-0.1:-71*rd;
yfit_p1 = f(constant_p1,xfit_p1);
%gradient of first data points
m_p1 = constant_p1(1);
%y-intercept of first data points
c_p1 = constant_p1(2);
%equation 2
line_p1 = m_p1*rpm-0.2877;

%p2
constant_p2 = lsqcurvefit(@f,[0;0],rpm_p2,t_p2);
xfit_p2 = -74*rd:-0.1: -91*rd;
yfit_p2 = f(constant_p2,xfit_p2);
%gradient of first data points
m_p2 = constant_p2(1);
%y-intercept of first data points
c_p2 = constant_p2(2);
%equation 2
line_p2 = m_p2*rpm-0.362;

%p3
constant_p3 = lsqcurvefit(@f,[0;0],rpm_p3,t_p3);
xfit_p3 = -95*rd:-0.1:-150*rd;
yfit_p3 = f(constant_p3,xfit_p3);
%gradient of first data points
m_p3 = constant_p3(1);
%y-intercept of first data points
c_p3 = constant_p3(2);
%equation 2
line_p3 = m_p3*rpm-0.4801;

constant3 = lsqcurvefit(@f,[0;0],rpm_n1,t_n1);
xfit_n1 = -55*rd:-0.1:-94*rd;
yfit_n1 = f(constant3,xfit_n1);
%gradient and y-intercept of data points
m3 = constant3(1);
c3 = constant3(2);
%equation that best represents curve 3
line_3 = m3*rpm + 0.3271;

constant4 = lsqcurvefit(@f,[0;0],rpm_n2,t_n2);
xfit_n2 = -97*rd:-0.1:-171*rd;
yfit_n2 = f(constant4,xfit_n2);
%gradient and y intercept of data sets
m4 = constant4(1);
c4 = constant4(2);
%equation that best represets curve 4
line_4 = m4*rpm + 0.4486;

% y = piecewise(-150<rpm<-95,line_2,-91<rpm<-74,line_1,-71<rpm<-43,line_p1);%40<rpm<90,line_3,90<rpm<150,line_4)
%y = piecewise(40<rpm<90,line_3,90<rpm<150,line_4)

% const_z = lsqcurvefit(@f,[0;0],z_rpm,z_t);
% xfit_z = -42:0.1:39;
% yfit_z = f(const_z,xfit_z);
% m_z = const_z(1);
% c_z = const_z(2);
% line_z = m_z*rpm;


y = piecewise(-150*rd<rpm<-95*rd,line_p3,-91*rd<rpm<-74*rd,line_p2,-71*rd<rpm<-43*rd,line_p1,40*rd<rpm<90*rd,line_3,90*rd<rpm<150*rd,line_4);

figure

%plot(rpm_n2,t_n2,'ro');
fplot(y,'ro');
axis([-150*rd 150*rd -1 1]);
%hold on
%plot(xfit_n2,yfit_n2);





