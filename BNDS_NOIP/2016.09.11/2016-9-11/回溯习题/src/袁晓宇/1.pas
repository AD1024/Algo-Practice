var
    a:array[1..20,1..20] of integer;
    b:array[1..100] of integer;
    n,t:integer;
procedure print;
var p,q:integer;
begin
  for p:=1 to n do
    begin
      for q:=1 to n do
        write(a[p,q],' ');
      writeln;
    end;
  writeln;
end;

procedure check1;
var p,s,f,q:integer;
begin
  s:=0;f:=0;
  for p:=1 to n do
    begin
      s:=0;
      for q:=1 to n do
        s:=s+a[q,p];
      if s<>t then begin f:=1; exit; end;
    end;
  s:=0;
  for p:=1 to n do
    s:=s+a[p,p];
  if s<>t then begin f:=1; exit; end;
  s:=0;
  for p:=1 to n do
    s:=s+a[p,n-p+1];
  if s<>t then begin f:=1; exit; end;
  if f=0 then print;
end;

function check2(i:integer):boolean;
var p,s:integer;
begin
  s:=0;
  for p:=1 to n do
    s:=s+a[i,p];
  if s<>t
    then begin check2:=false; exit; end
    else check2:=true;
end;

procedure try(i,j:integer);
var m:integer;
begin
  for m:=1 to n*n do
    if b[m]=0 then
      begin
        a[i,j]:=m;
        b[m]:=1;
        if (i=n)and(j=n) then check1;
        if j=n
          then begin if check2(i) then try(i+1,1) end
          else try(i,j+1);
        a[i,j]:=0;
        b[m]:=0;
      end;
end;

begin
    assign(input,'1.in');
    assign(output,'1.out');
    reset(input);
    rewrite(output);
    readln(n);
    t:=n*(n*n+1) div 2;
    try(1,1);
    close(input);
    close(output);
end.