int readInt(){
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n'){
        a *= 10;
        a += ch - '0';
    }
    return a;
}
