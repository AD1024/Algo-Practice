

Program CowRun ( Input , Output ) ;

Const
        Fn                      = 'cowrun' ;
        Fi                      = '.in'    ;
        Fo                      = '.out'   ;
Type
        Int                     = Integer ;
        Long                    = Longint ;
        Bool                    = Boolean ;
        Code                    = Array [ 0 .. 10000 ] of Long ;
Var
        i , j , k , n , m , r   : Long ;
        g , s                   : Code ;


Begin
        Assign  ( Input  , Fn + Fi ) ;
        Reset   ( Input  ) ;
        Assign  ( Output , Fn + Fo ) ;
        Rewrite ( Output ) ;

        Fillchar ( g , sizeof ( g ) , 0 ) ;
        Fillchar ( s , sizeof ( s ) , 0 ) ;
        Readln ( n , m ) ;
        For i := 1 to n do
        Begin
                Readln ( k ) ;
                s [ i ] := s [ i - 1 ] + k ;
        End ;

        For i := 1 to n do
        Begin
                If i div 2 < m Then k := i div 2 Else k := m ;
                For j := i - 2 * k to i - 1 do
                Begin
                        r := ( i - j ) div 2 ;
                        If g [ j ] + s [ j + r ] - s [ j ] > g [ i ]
                        Then g [ i ] := g [ j ] + s [ j + r ] - s [ j ] ;
                End ;
        End ;

        Writeln ( g [ n ] ) ;

        Close ( Input  ) ;
        Close ( Output ) ;
End .