fid=datastore('test_result.txt');
T=read(fid);
n=T{:,1};
data_Strassen=T{:,2};
data_tradition=T{:,3};

plot(n,data_Strassen,n,data_tradition);
title('compare Strassen Algorithm & traditional method ')
xlabel('matrix with n colums & n rows');
ylabel('spend time(clocks)');
legend('Strassen','tradition');

