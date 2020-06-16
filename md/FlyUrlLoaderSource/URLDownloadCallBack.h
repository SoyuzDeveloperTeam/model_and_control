// URLDownloadCallBack.h
// А. Николенко 03.05.2019
//
//-----------------------------------------------------------------------------
#ifndef CURL_DOWNLOAD_CALL_BACK_H
#define CURL_DOWNLOAD_CALL_BACK_H

// Регистрируем класс производный от IBindStatusCallback
class FLYURLLOADER_API CUrlDownloadCallBack :public IBindStatusCallback
{
public:
	CUrlDownloadCallBack(
		unsigned int ID, 
		int(*pUserCB)(unsigned int ID, float p) = nullptr);
	~CUrlDownloadCallBack();

	//члены IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, void ** ppvObject);
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);

	//Члены IBindStatusCallback
	STDMETHODIMP OnStartBinding(DWORD grfBSCOption, IBinding *pib);
	STDMETHODIMP OnStopBinding(HRESULT hresult, LPCWSTR szError);
	STDMETHODIMP OnObjectAvailable(REFIID riid, IUnknown *punk);
	STDMETHODIMP OnLowResource(DWORD dwReserved);
	STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax,
		ULONG ulStatusCode, LPCWSTR szStatusText);
	STDMETHODIMP GetBindInfo(DWORD *pgrfBINDF, BINDINFO *pbindInfo);
	STDMETHODIMP GetPriority(LONG *pnPriority);
	STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize,
		FORMATETC *pformatetc,
		STGMEDIUM *pstgmed);
	bool SetWindow(HWND hWnd);
	bool GetWindow(HWND *phWnd);
	bool Abort(void);
	bool isWasBreak();
	float WhereWasBreak();

private:
	//Счетчик ссылок
	int(*pUserCallBack)(unsigned int ID, float p);
	unsigned int IDL;
	int   cRef;
	HWND  hWndInternal;
	bool  bAbort;
	float posWasBreak;
};

//-----------------------------------------------------------------------------
#endif // #ifndef CURL_DOWNLOAD_CALL_BACK_H