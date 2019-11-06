#ifdef lexico
#define lexico
    void id (char letter);
    void numero (char digit);
    void comment (char letter);
    string keyword (string lexema);
    string typeToken ();
    void insertList ();
    bool createTokens();
#endif