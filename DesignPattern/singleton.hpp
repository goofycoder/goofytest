class Singleton 
{
public:
    static volatile Singleton* volatile getInstance();

private:
    static volatile Singleton* volatile pInstance;        
};
