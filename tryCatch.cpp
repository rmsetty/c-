class Rectangle
{
    private:
    int width;
    int length;
    
    public:
    Rectangle(int w, int h) : width(w), length(l)
    {
        if(width < 0|| length < 0)
        {
            throw(Negative("You are dumb"));
        }
    }
    
    class Negative
    {
        private:
        string message;
        
        public:
        Negative(string m) : message(m){};
        string getMessage(){return message;}
    }
}

int main()
{
    try
    {
        Rectangle r(5, -3);
    }
    
    catch(Rectangle :: Negative e)
    {
        cout << e.getMessage() << endl;
    }
}



