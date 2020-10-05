//////////////////////////////////////////////////////////////////////////
/**
 *   C++ implementation of Exponential Smoothing
 *

 *
 *   
 *
 *
 *  
//////////////////////////////////////////////////////////////////////////

#ifndef HEADER_EXPONENTIAL_SMOOTHING_H
#define HEADER_EXPONENTIAL_SMOOTHING_H

#include <limits>
#include <iostream>
#include <cassert>

/** Class data_vec defines a D-dimensional vector
 *  \T Data type of vector
 *  \D Dimension of vector
 */
template <typename T, size_t D>
class es_vec
{
public:
    /** Default constructor*/
    es_vec()
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = std::numeric_limits<T>::lowest();
    }

    /** Create a vector with an initial value _v for all elements */
    es_vec(const T _v)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = _v;
    }

    /** Copy constructor*/
    es_vec(const es_vec<T, D> & _vec)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = _vec.esv_data[i];
    }

    /** Destructor*/
    ~es_vec()
    {

    }

public:
    /** Reset the vector with a specified value _v */
    void reset(const T _v = 0)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = _v;
    }

    /** Init from a raw vector */
    void init(const T* _data)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = _data[i];
    }

    /** Operator [] */
    T & operator [] (const size_t _i)
    {
        return esv_data[_i];
    }

    const T & operator [] (const size_t _i) const
    {
        return esv_data[_i];
    }

    /** Operator = */
    es_vec<T, D> & operator = (const es_vec<T, D> & _vec)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] = _vec.esv_data[i];
        return *this;
    }

    /** Operator += */
    es_vec<T, D> & operator += (const es_vec<T, D> & _vec)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] += _vec[i];
        return *this;
    }

    /** Operator -= */
    es_vec<T, D> & operator -= (const es_vec<T, D> & _vec)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] -= _vec[i];
        return *this;
    }

    /** Operator *= */
    es_vec<T, D> & operator *= (const T _v)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] *= _v;
        return *this;
    }

    /** Operator /= */
    es_vec<T, D> & operator /= (const T _v)
    {
        for (size_t i = 0; i < D; ++i) esv_data[i] /= _v;
        return *this;
    }

    /** get the raw data vector */
    T* raw_data()
    {
        return esv_data;
    }

    /** return the 2-norm of this vector */
    const T norm() const
    {
        T norm(0);
        for (size_t i = 0; i < D; ++i) norm += esv_data[i] * esv_data[i];
        return sqrt(norm);
    }

    /** ************* Friend functions to provide more operators ****************************** */
    /** Operator + */
    friend es_vec<T, D> operator + (const es_vec<T, D> & _vec1, const es_vec<T, D> & _vec2)
    {
        return es_vec<T, D>(_vec1) += _vec2;
    }

    /** Operator - */
    friend es_vec<T, D> operator - (const es_vec<T, D> & _vec1, const es_vec<T, D> & _vec2)
    {
        return es_vec<T, D>(_vec1) -= _vec2;
    }

    /** Operator * */
    friend es_vec<T, D> operator * (const T _v, const es_vec<T, D> & _vec)
    {
        return es_vec<T, D>(_vec) *= _v;
    }

    friend es_vec<T, D> operator * (const es_vec<T, D> & _vec, const T _v)
    {
        return es_vec<T, D>(_vec) *= _v;
    }

    /** Operator / */
    friend es_vec<T, D> operator / (const es_vec<T, D> & _vec, const T _v)
    {
        return es_vec<T, D>(_vec) /= _v;
    }

    /** Operator == */
    friend const bool operator == (const es_vec<T, D> & _vec1, const es_vec<T, D> & _vec2)
    {
        for (size_t i = 0; i < D; ++i)
        {
            if (!_vec1[i] == _vec2[i]) return false;
        }
        return true;
    }

    /** Operator != */
    friend const bool operator != (const es_vec<T, D> & _vec1, const es_vec<T, D> & _vec2)
    {
        for (size_t i = 0; i < D; ++i)
        {
            if (!_vec1[i] == _vec2[i]) return true;
        }
        return false;
    }

    /** Operator << */
    friend std::ostream & operator << (std::ostream & _os, const es_vec<T, D> & _vec)
    {
        _os << "[";
        for (size_t i = 0; i < D - 1; ++i) _os << _vec[i] << " ";
        _os << _vec[D - 1] << "]";
        return _os;
    }

private:
    T esv_data[D];
};

/** Single Exponential Smoothing Method
 *  \T Data type float/double/double double...
 *  \D Dimension of this class
 */
template <typename T, size_t D>
class single_exponential_smoothing
{
public:
    /** Default constructor */
    single_exponential_smoothing() : ses_smoothing_const(0.5), ses_counter(0), ses_vacillation_tolerance(0)
    {
        ses_curr_smoothed_ob.reset();
    }

    /** Destructor */
    ~single_exponential_smoothing()
    {

    }

public:
    /** Set the value of smoothing constant in the range (0, 1) */
    void set_smoothing_constant(const T _val)
    {
        assert(_val > 0 && _val < 1);
        ses_smoothing_const = _val;
    }

    /** Set the value of vacillation tolerance */
    void set_vacillation_tolerance(const T _val)
    {
        ses_vacillation_tolerance = _val;
    }

    /** Push a new vec and pop its smoothed value as the return */
    const es_vec<T, D> push_to_pop(const es_vec<T, D> _curr_raw_ob)
    {
        if(0 < ses_counter)
        {
            es_vec<T, D> temp_last_smoothed_ob(ses_curr_smoothed_ob);

            ses_curr_smoothed_ob = ses_smoothing_const * _curr_raw_ob + (1 - ses_smoothing_const) * ses_curr_smoothed_ob;

            if ((ses_curr_smoothed_ob - temp_last_smoothed_ob).norm() < ses_vacillation_tolerance)
            {
                ses_curr_smoothed_ob = temp_last_smoothed_ob;
            }
        }
        else
        {
            ses_curr_smoothed_ob = _curr_raw_ob;
        }

        ++ses_counter;

        return ses_curr_smoothed_ob;
    }

    /** Get the current counter */
    const size_t counter() const { return ses_counter; }

    /** Reset this class to initial state */
    void reset()
    {
        ses_curr_smoothed_ob.reset();
        ses_smoothing_const = 0.5;
        ses_counter = 0;
        ses_vacillation_tolerance = 0;
    }

private:
    es_vec<T, D> ses_curr_smoothed_ob;

    T ses_smoothing_const;

    size_t ses_counter;

    T ses_vacillation_tolerance;
};

/** Double Exponential Smoothing Method
 *  \T Data type float/double/double double...
 *  \D Dimension of this class
 */
template <typename T, size_t D>
class double_exponential_smoothing
{
public:
    /** Default constructor */
    double_exponential_smoothing() :
            des_1st_smoothing_const(0.5),
            des_2nd_smoothing_const(0.5),
            des_counter(0),
            des_vacillation_tolerance(0)
    {
        des_curr_smoothed_ob.reset();
        des_last_smoothed_ob.reset();
        des_curr_correction_ob.reset();
    }

    /** Destructor */
    ~double_exponential_smoothing()
    {

    }

public:
    /** Set the value of 1st smoothing constant in the range (0, 1) */
    void set_1st_smoothing_constant(const T _val)
    {
        assert(_val > 0 && _val < 1);
        des_1st_smoothing_const = _val;
    }

    /** Set the value of 2nd smoothing constant in the range (0, 1) */
    void set_2nd_smoothing_constant(const T _val)
    {
        assert(_val > 0 && _val < 1);
        des_2nd_smoothing_const = _val;
    }

    /** Set the value of vacillation tolerance */
    void set_vacillation_tolerance(const T _val)
    {
        des_vacillation_tolerance = _val;
    }

    /** Push a new vec and pop its smoothed value as the return */
    const es_vec<T, D> push_to_pop(const es_vec<T, D> _curr_raw_ob)
    {
        if (0 == des_counter)
        {
            des_curr_smoothed_ob = _curr_raw_ob;
        }
        else if (1 == des_counter)
        {
            des_curr_correction_ob = _curr_raw_ob - des_curr_smoothed_ob;

            des_last_smoothed_ob = des_curr_smoothed_ob;

            des_curr_smoothed_ob = des_1st_smoothing_const * _curr_raw_ob +
                    (1 - des_1st_smoothing_const) * (des_curr_smoothed_ob + des_curr_correction_ob);

            if ((des_curr_smoothed_ob - des_last_smoothed_ob).norm() < des_vacillation_tolerance)
            {
                des_curr_smoothed_ob = des_last_smoothed_ob;
            }
        }
        else
        {
            des_curr_correction_ob = des_2nd_smoothing_const * (des_curr_smoothed_ob - des_last_smoothed_ob) +
                    (1 - des_2nd_smoothing_const) * des_curr_correction_ob;

            des_last_smoothed_ob = des_curr_smoothed_ob;

            des_curr_smoothed_ob = des_1st_smoothing_const * _curr_raw_ob +
                    (1 - des_1st_smoothing_const) * (des_curr_smoothed_ob + des_curr_correction_ob);

            if ((des_curr_smoothed_ob - des_last_smoothed_ob).norm() < des_vacillation_tolerance)
            {
                des_curr_smoothed_ob = des_last_smoothed_ob;
            }
        }

        ++des_counter;

        return des_curr_smoothed_ob;
    }

    /** Get the current counter */
    const size_t counter() const { return des_counter; }

    /** Reset this class to initial state */
    void reset()
    {
        des_curr_smoothed_ob.reset();
        des_last_smoothed_ob.reset();
        des_curr_correction_ob.reset();

        des_1st_smoothing_const = 0.5;
        des_2nd_smoothing_const = 0.5;

        des_counter = 0;
    }

private:
    es_vec<T, D> des_curr_smoothed_ob;
    es_vec<T, D> des_last_smoothed_ob;
    es_vec<T, D> des_curr_correction_ob;

    T des_1st_smoothing_const;
    T des_2nd_smoothing_const;

    size_t des_counter;

    T des_vacillation_tolerance;
};

#endif // HEADER_EXPONENTIAL_SMOOTHING_H
