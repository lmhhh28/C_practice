#include<iostream>




template <class _Tp>
class vector {
    private:
        _Tp* _M_start, _M_finish, _M_end_of_shorage;
    public:
        using value_type        =   T;
        using reference         =   value_type&;
        using const_reference   =   const value_type&;
        using pointer           =   value_type
        using iterator          =   value_type*;
    
        vector() : data(nullptr), cap(0), len(0) {}
        vector(size_t , const_reference = value_type()); 
        template <class InputIt> vector(InputIt begin, InputIt end);
        vector(const vector& other);

};