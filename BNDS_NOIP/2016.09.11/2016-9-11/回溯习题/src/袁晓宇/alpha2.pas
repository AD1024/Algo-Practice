var
    a,b:array[1..100] of integer;
    c:array[0..100,0..100] of boolean;
    n,s,s1:integer;
procedure f(m:integer);
var i,j,k:integer; l:array[1..4] of boolean;
begin
  j:=10;
  fillchar(l,sizeof(l),true);
  if m div 1000<>0
    then
      for k:=1 to 3 do
        begin
         for i:=1 to n do
           if l[k]
             then
               if m mod j=a[i]
                 then begin l[k]:=false; break; end;
         j:=j*10;
        end
    else
      for k:=1 to 3 do
        begin
         for i:=1 to n do
           if l[k]
             then
               if m mod j=a[i]
                 then begin l[k]:=false; break; end;
         j:=j*10;
        end;
end;

procedure try(j:integer);
var t,t1,t2,i:integer;
begin
  if j=5 then
    begin
      s1:=b[1]*100+b[2]*10+b[3];
      t:=s1*b[4];
      t1:=s1*b[5]*10;
      t2:=s1*(b[4]*10+b[5]);
      s1:=t+t1;
      f(t);
      f(t1);
      f(t2);
      f(s1);
      if (s1 div 10000<>0)or(t2 div 10000<>0) then exit;
      if t2=s1 then inc(s);
      exit;
    end;
  if j<5
    then
      for i:=1 to 5 do
        if c[i,j]=true
          then
            begin
              c[i,j]:=false;
              b[j+1]:=a[i];
              try(j+1);
            end;

end;

begin
    assign(input,'alpha2.in');
    assign(output,'alpha2.out');
    reset(input);
    rewrite(output);
    readln(n);
    for s:=1 to n do
      read(a[s]);
    fillchar(c,sizeof(c),true);
    s:=0;
    try(0);
    writeln(s);
    close(input);
    close(output);
end.
