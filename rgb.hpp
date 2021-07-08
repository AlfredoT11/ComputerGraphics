class RGBColor{
    public:
        int R;
        int G;
        int B;

        RGBColor(int Rvalue, int GValue, int BValue);
};

class Image{
    public:
        int width;
        int height;    
        RGBColor **pixelsArray;

        Image(int width, int height);
};