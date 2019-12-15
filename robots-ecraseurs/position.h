#ifndef POSITION_H
#define POSITION_H


class position
{
    public:
        position(int x=0, int y=0);
        position(const position &pos);
        ~position();
        int x() const;
        int y() const;
        void modifie(int x, int y);
        void modifie(const position &pos);
        void decale(int dx, int dy);
        bool operator==(const position& pos) const;

    protected:

    private:
        int d_x;
        int d_y;
};

#endif // POSITION_H
