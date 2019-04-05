function out = ts_derivative(sig)
 % outputs a time_series derivative of the input time_series sig.
    data=[];
    data(1)=0;
    for j=2:length(sig.Data)
      data(j)=(sig.Data(j)-sig.Data(j-1))/(86400*(sig.Time(j)-sig.Time(j-1)));
    end
    out=timeseries(data',sig.Time,'Name',[sig.Name, '_dot']);
end
