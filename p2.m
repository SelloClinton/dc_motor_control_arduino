constant = lsqcurvefit(@f,[0;0],rpmP2,t_p2);
m = constant(1);
c = constant(2);
xfit2 = 95:0.1:150;
yfit2 = f(constant,xfit2);


figure
plot(rpmP2,t_p2);
hold on
plot(xfit2,yfit2);