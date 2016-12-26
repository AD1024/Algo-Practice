#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;
#include <iterator>
using std::ostream_iterator;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
#include <algorithm>
using std::reverse;
using std::max;
using std::lexicographical_compare;
using std::find;
#include <string>
using std::string;
#include <iterator>
using namespace std;
#include <cmath>

class BigInt : public vector<long long> {
    bool negative;

public:
    BigInt(long long num = 0);
    BigInt operator +(const BigInt&) const ;
    BigInt operator += (const BigInt&);
    BigInt operator -(const BigInt&) const ;
    BigInt operator -= (const BigInt&);
    BigInt operator * (const BigInt&) const ;
    BigInt operator *= (const BigInt&);
    BigInt operator / (long long num) const ;
    BigInt operator ^ (unsigned index) const ;
    inline bool operator < (const BigInt&) const ;
    inline bool operator > (const BigInt&) const ;
    inline bool operator <= (const BigInt&) const ;
    inline bool operator >= (const BigInt&) const ;
    friend inline istream &operator >> (istream&, BigInt&);
    friend inline ostream &operator << (ostream&, BigInt&);
} dp[88][88], ans;

const unsigned sys(100000); // 压位

BigInt::BigInt(long long num) {
    negative = num < 0;
    do
        this->push_back(num % sys);
    while (num /= sys);
}

BigInt BigInt:: operator +(const BigInt &num) const {
    BigInt result, a = *this, b = num;
    a.negative = b.negative = false;
    if (this->negative)
        if (num.negative) {
            result = a + b;
            result.negative = true;
            return result;
        }
        else
            return b - a;
    else if (num.negative)
        return a - b;
    else {
        size_t max_size(std::max(num.size(), size()));
        a.resize(max_size, 0);
        b.resize(max_size, 0);
        for (size_t i(0); i < max_size; result[i++] %= sys)
            result.push_back((result[i] += b[i] + a[i]) / sys);
        while (result.size() > 1 && *result.rbegin() == 0)
            result.erase(result.end() - 1);
        return result;
    }
}

BigInt BigInt:: operator += (const BigInt &num) {
    return *this = *this +num;
}

BigInt BigInt:: operator -(const BigInt &num) const {
    BigInt result, a(*this), b(num);
    a.negative = b.negative = false;
    if (negative)
        if (num.negative)
            return b - a;
        else {
            result = a + b;
            result.negative = !result.negative;
            return result;
        }
    else if (num.negative)
        return a + b;
    else {
        if (a < b) {
            a.swap(b);
            a.negative = true;
        }
        b.resize(a.size(), 0);
        for (size_t i(0); i < a.size(); ++i) {
            if (a[i] < b[i])
                a[i] += sys, --a[i + 1];
            a[i] -= b[i];
        }
        while (a.size() > 1 && *a.rbegin() == 0)
            a.erase(a.end() - 1);
        return a;
    }
}

BigInt BigInt:: operator -= (const BigInt &num) {
    return *this = *this -num;
}

BigInt BigInt:: operator *(const BigInt &num) const {
    if (*this == BigInt() || num == BigInt())
        return BigInt();
    BigInt result;
    result.negative = negative ^ num.negative;
    result.resize(size() + num.size(), 0);
    for (size_t i(0); i < size(); ++i)
        for (size_t j(0); j < num.size(); ++j)
            result[i + j] += at(i) * num[j];
    for (size_t i(0); i < result.size() - 1; ++i)
        result[i + 1] += result[i] / sys, result[i] %= sys;
    while (*result.rbegin() == 0)
        result.erase(result.end() - 1);
    return result;
}

BigInt BigInt:: operator *= (const BigInt &num) {
    return *this = *this*num;
}

BigInt BigInt:: operator / (long long num) const {
    BigInt result(*this);
    return result;
}

BigInt BigInt:: operator ^ (unsigned index) const {
    BigInt result(1), base = *this;
    for (; index; base *= base, index >>= 1)
        if (index & 1)
            result *= base;
    return result;
}

Bigint Bigint::operator %(const BigInt& num)const{
    BigInt res=*this/num;
    res=*this-res*num;
    return res;
}

inline bool BigInt:: operator < (const BigInt &num) const {
    if (negative ^ num.negative)
        return negative;
    if (size() == num.size()) {
        for (int i(size() - 1); i >= 0; --i)
            if (at(i) != num[i])
                return at(i) < num[i] ^ negative;
        return false;
    }
    else
        return size() < num.size() ^ negative;
}

inline bool BigInt:: operator > (const BigInt &num) const {
    return num < *this;
}

inline bool BigInt:: operator <= (const BigInt &num) const {
    return !(num < *this);
}

inline bool BigInt:: operator >= (const BigInt &num) const {
    return !(*this < num);
}

inline istream &operator >> (istream &in, BigInt &num) {
    num.clear();
    num.negative = false;
    string data;
    in >> data;
    if (data[0] == '-')
        data.erase(0, 1), num.negative = true;
    int tmp(0);
    for (size_t i(data.size()), cnt(1); i--; cnt *= 10)
        if (cnt < sys)
            tmp += cnt * (data[i] - '0');
        else {
            num.push_back(tmp);
            tmp = data[i] - '0';
            cnt = 1;
        }
    num.push_back(tmp);
    return in;
}

inline ostream &operator << (ostream &out, BigInt &num) {
    if (num.negative)
        out.put('-');
    for (BigInt::reverse_iterator i(num.rbegin()); i < num.rend(); out << *i++)
        if (i != num.rbegin())
            for (int j(0); j < (*i ? int(log10(sys))-int(log10(*i) + 1) :
                log10(sys) - 1); ++j)
                out.put('0');
    return out;
}