//-------------------------------------------------------------------------------
// ZMessageManager.h : 
// А. Николенко 17.10.2018
//-------------------------------------------------------------------------------
class FLYCORE_API ZMessageManager {
public:
	ZMessageManager () ;			
	~ZMessageManager() ;			

	void  Clear() ;			
	int   Size() ;
	void  Add(char* Msg) ;
	char* First() ;
	char* Next() ;
	char* Prev() ;
	char* Last() ;

protected :
	vector<string>  MessageList ;
	int indexMsg ;
} ;

FLYCORE_API  ZMessageManager& operator << (ZMessageManager& MM, char* Msg);
FLYCORE_API void operator >> (char* Msg, ZMessageManager& MM);
FLYCORE_API void operator >> (ZMessageManager& MM, FILE* pf);
FLYCORE_API void operator << (FILE* pf, ZMessageManager& MM);

FLYCORE_API extern ZMessageManager MsgManager;

//-------------------------------------------------------------------------------
