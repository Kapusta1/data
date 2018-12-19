//Class Smart_Pointer
template<typename T>
class smart_point
{
private :
	T * m_pRawPointer;
public:
	smart_point(T*pData) :m_pRawPointer(pData) {}
	~smart_point() { delete m_pRawPointer; }

	T& operator*()const
	{
		return *(m_pRawPointer);
	}
	T*operator->()const
	{
		return m_pRawPointer;
	}
};