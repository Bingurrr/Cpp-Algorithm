#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

class myPolynomial;

class myTerm {
private:
    //int coeff;      // integer coefficient
    //unsigned exp;   // exponent (non-negative integer)
public:
    int coeff;      // integer coefficient
    unsigned exp;
    myTerm(int c = 0, unsigned e = 0);
    // copy constructor
    myTerm(const myTerm& term);

    // accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }

    // mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }

    // member functions
    myTerm ddx() const;     // derivative of a term

    // overloaded operators
    myTerm operator- () const;

    // friend functions and classes
    friend  bool operator== (const myTerm& t1, const myTerm& t2);
    friend  bool operator< (const myTerm& t1, const myTerm& t2);
    friend  ostream& operator<<(ostream& os, const myTerm& term);
    friend class myPolynomial;

};

// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e) {}
// copy constructor
myTerm::myTerm(const myTerm& term) : coeff(term.coeff), exp(term.exp) {}

myTerm myTerm::operator- () const {
    // fill in
    myTerm ret = myTerm(this->getCoeff(), this->getExp());
    int k = ret.getCoeff() * (-1);
    ret.setCoeff(k);
    return ret;
}
// derivative of a term
myTerm myTerm::ddx() const {
    if (exp == 0)
        return myTerm(0, 0);

    return myTerm(exp * coeff, exp - 1);
}
// overloaded operators
bool operator== (const myTerm& t1, const myTerm& t2) {
    // fill in
    if (t1.getCoeff() == t2.getCoeff()) {
        if (t1.getExp() == t2.getExp()) {
            return true;
        }
    }
    return false;
}
bool operator!= (const myTerm& t1, const myTerm& t2) {
    // fill in
    return !(t1 == t2);
}

// overloaded operators
bool operator< (const myTerm& t1, const myTerm& t2) {
    return t1.exp < t2.exp;
}
bool operator>(const myTerm& c1, const myTerm& c2) { return c2 < c1; }
bool operator<=(const myTerm& c1, const myTerm& c2) { return !(c1 > c2); }
bool operator>=(const myTerm& c1, const myTerm& c2) { return !(c1 < c2); }

// output operator
ostream& operator<<(ostream& os, const myTerm& term) {
    if (term.exp == 0) {
        if (term.coeff == 0)        // nothing to output
            return os;
        else
            return os << term.coeff;
    }
    if (term.coeff == 1)
        os << "x";
    else if (term.coeff == -1)
        os << "-x";
    else
        os << term.coeff << "x";

    if (term.exp == 1)
        return os;
    else
        return os << "^" << term.exp;
}
bool Cmp(myTerm a, myTerm b) {
    return a.exp > b.exp;
}
class myPolynomial {
private:
    //int degree;     // maximum exponent
    //vector<myTerm> terms;

    void reduce();
    long ipow(int x, int n) const;

    typedef vector<myTerm>::iterator termIt;
    typedef vector<myTerm>::const_iterator termCIt;

public:
    int degree;
    vector<myTerm> terms;
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial& poly);

    // overloaded operators
    myPolynomial& operator += (const myPolynomial& poly);
    myPolynomial& operator -= (const myPolynomial& poly);
    myPolynomial& operator *= (const myPolynomial& poly);
    //myPolynomial& operator *= (int k);

    myPolynomial operator -() const;
    //myPolynomial operator *(int k) const;


    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const;     // get a degree of the polynomial
    unsigned getNumTerms() const;   // number of terms in the polynomial
    myPolynomial ddx() const;       // derivative of a polynomial

    friend bool Cmp(myTerm a, myTerm b);
    // friend operators and functions
    friend bool operator== (const myPolynomial& p1, const myPolynomial& p2);
    //  friend myPolynomial operator*(int k, const myPolynomial& poly);
    friend ostream& operator<<(ostream& os, const myPolynomial& poly);

    static const myPolynomial ZERO;     // P(x) = 0
    static const myPolynomial ONE;      // P(x) = 1
    static const myPolynomial X;        // P(x) = x
};

// Constructor
myPolynomial::myPolynomial(int c, unsigned e) {
    if (c == 0) {   // the zero polynomial has degree -1
        terms.clear();
        degree = -1;
    }
    else {
        terms.clear();
        terms.push_back(myTerm(c, e));
        degree = e;
    }
    sort(terms.begin(), terms.end(), Cmp);
}

// Constructor
myPolynomial::myPolynomial(int nTerms, int mono[]) {
    // fill in
    for (int i = nTerms; i > 0; i--) {
        myTerm tmp(mono[2 * i-2], mono[2 * i-1]);
        terms.push_back(tmp);
    }
    sort(terms.begin(), terms.end(), Cmp);

    if (nTerms == 1 && terms[0].coeff == 0 && terms[0].exp == 0)  degree = 0;
    else  degree = mono[1];
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial& poly) : terms(poly.terms), degree(poly.degree) {}
// overloaded operator +

myPolynomial operator+(myPolynomial lhs, const myPolynomial& p) {
    // fill in
    myPolynomial ret(lhs);
    int arr[111] = { 0 };
    auto a = 0, b = 0;
    int index = 0;
    for (index; a != lhs.terms.size() && b != p.terms.size(); index++) {
        if (lhs.terms[a].exp > p.terms[b].exp) {
            arr[index * 2] = lhs.terms[a].coeff;
            arr[index * 2 + 1] = lhs.terms[a].exp;
            a++;
        }
        else if (lhs.terms[a].exp < p.terms[b].exp) {
            arr[index * 2] = p.terms[b].coeff;
            arr[index * 2 + 1] = p.terms[b].exp;
            b++;
        }
        else {
            arr[index * 2] = lhs.terms[a].coeff + p.terms[b].coeff;
            arr[index * 2 + 1] = lhs.terms[a].exp;
            a++;
            b++;
        }
    }
    for (a; a != lhs.terms.size(); a++) {
        arr[index * 2] = lhs.terms[a].coeff;
        arr[index * 2 + 1] = lhs.terms[a].exp;
        index++;
    }
    for (b; b != p.terms.size(); b++) {
        arr[index * 2] = p.terms[b].coeff;
        arr[index * 2 + 1] = p.terms[b].exp;
        index++;
    }
    int* answer = new int[index*2];
    for (int i = 0; i < index; i++) {
        answer[2 * i] = arr[2 * i];
        answer[2 * i + 1] = arr[2 * i + 1];
    }
    return myPolynomial(index, answer);


}
myPolynomial operator-(myPolynomial lhs, const myPolynomial& p) {
    // fill in
    return lhs + (-p);
}
myPolynomial operator*(myPolynomial lhs, const myPolynomial& p) {
    // fill in
    myPolynomial ret(0, (unsigned)0);

    for (int i = 0; i < lhs.terms.size(); i++) {
        myPolynomial tmp(p);
        for (int j = 0; j < p.terms.size(); j++) {
            tmp.terms[j].coeff *= lhs.terms[i].coeff;
            tmp.terms[j].exp = lhs.terms[i].exp + tmp.terms[j].exp;

        }
        ret += tmp;
    }

    return ret;
}
//*int


// overloaded operator +=
myPolynomial& myPolynomial::operator += (const myPolynomial& poly) {
    *this = *this +poly;
    return *this;
}

// overloaded operator -=
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly) {
    // fill in
    *this = *this - poly;
    return *this;
}

// overloaded operator *=
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly) {
    // fill in 
    *this = *this * poly;
    return *this;
}


// unary operator -
myPolynomial myPolynomial::operator -() const {
    // fill in
    myPolynomial ret = *(this) * (-1);
    return ret;
}


long myPolynomial::operator() (int x) const {
    // fill in
    long ret = 0;
    for (int i = 0; i < terms.size(); i++) {
        ret += terms[i].coeff * pow(x, terms[i].exp);
    }
    return ret;

}
int myPolynomial::getDegree() const {
    if(terms.size() <= 1) return -1;
    return terms[0].exp;
}
unsigned myPolynomial::getNumTerms() const {
    // fill in
    return terms.size();
}
// derivative of a poly
myPolynomial myPolynomial::ddx() const {
    // fill in
    myPolynomial ret(*this);

    for (int i = 0; i < terms.size(); i++) {
        ret.terms[i] = terms[i].ddx();
    }
    return ret;
}
// overloaded operator ==
bool operator== (const myPolynomial& p1, const myPolynomial& p2) {
    // fill in
    if (p1.getNumTerms() != p2.getNumTerms()) return false;

    for (int i = 0; i < p1.getNumTerms(); i++) {
        if (p1.terms[i].coeff != p2.terms[i].coeff || p1.terms[i].exp != p2.terms[i].exp)
            return false;
    }
    return true;
}
bool operator!= (const myPolynomial& p1, const myPolynomial& p2) {
    return !(p1 == p2);
}
// output operator
ostream& operator<<(ostream& os, const myPolynomial& poly) {
    if (poly == myPolynomial::ZERO)
        return os << 0;
    // fill in
    int count = 0;
    for (int i = 0; i < poly.terms.size(); i++) {
        if (poly.terms[i].coeff == 0)
            continue;
        else {
            count++;
            myTerm tmp = poly.terms[i];
            if (i == 0) { os << tmp; continue; }
            if (poly.terms[i].coeff > 0)  os << '+';
            os << tmp;
        }
    }
    if (count == 0) cout << 0;
    return os;

}
// power x^n for an integer x
// long myPolynomial::ipow(int x, int n) const {
//  // fill in
//  return 0;
// }
// reduce the terms in a polynomial data structure
void myPolynomial::reduce() {
    // fill in

}
const myPolynomial myPolynomial::ZERO(0);   // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0);   // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);   // the monomial P(x) = x

void testSimpleCase();
void testDataFromFile(int);

int main(void) {
    int numTerms;

    cin >> numTerms;
    if (numTerms)   testDataFromFile(numTerms);
    else            testSimpleCase();
}

void testSimpleCase() {
    // test static variables
    cout << "ZERO : " << myPolynomial::ZERO << endl;
    cout << "ONE : " << myPolynomial::ONE << endl;
    cout << "X : " << myPolynomial::X << endl;

    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);

    int testData4[10] = { 1, 0, 1, 1, 1, 2, 1, 3, 1, 4 };
    int testData5[10] = { -1, 0, -1, 1, -1, 2, -1, 3, -1, 4 };
    int testData6[10] = { 1, 0, -1, 1, 1, 2, -1, 3, 1, 4 };
    int testData7[10] = { 2, 2, 5, 5, 4, 4, 1, 1, 3, 3 };
    int testData8[12] = { 1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0 };

    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);

    // test constructor
    cout << "p0(x)= " << p0 << endl << "p1(x)= " << p1 << endl << "p2(x)= " << p2 << endl;
    cout << "p3(x)= " << p3 << endl << "p4(x)= " << p4 << endl << "p5(x)= " << p5 << endl;
    cout << "p6(x)= " << p6 << endl << "p7(x)= " << p7 << endl << "p8(x)= " << p8 << endl;

    // test copy constructor
    cout << "p9(x)= " << p9 << endl;

    // test accessor function
    cout << "the degree pf p8(x) is " << p8.getDegree() << " and the number of terms is " << p8.getNumTerms() << endl;

    // test evaluation function
    cout << "p0(2)= " << p0(2) << endl << "p1(2)= " << p1(2) << endl << "p2(2)= " << p2(2) << endl;
    cout << "p3(3)= " << p3(3) << endl << "p4(3)= " << p4(3) << endl << "p5(3)= " << p5(3) << endl;
    cout << "p6(1)= " << p6(1) << endl << "p7(1)= " << p7(1) << endl << "p8(1)= " << p8(1) << endl;

    // test comparison operators
    cout << "p7 == p9 is " << (p7 == p9) << " and p7 != p9 is " << (p7 != p9) << endl;

    // test derivative function
    cout << "derivative of ZERO is " << myPolynomial::ZERO.ddx() << endl;
    cout << "derivative of ONE is " << myPolynomial::ONE.ddx() << endl;
    cout << "derivative of X is " << myPolynomial::X.ddx() << endl;
    cout << "derivative of p4(x) is " << p4.ddx() << endl;
    cout << "derivative of p8(x) is " << p8.ddx() << endl;

    // test unary operator -
    cout << "-ZERO is " << -myPolynomial::ZERO << endl;
    cout << "-p4(x) is " << -p4 << endl;

    // test k*p(x) or p(x) * k
    cout << "3 x ZERO = " << 3 * myPolynomial::ZERO << endl;
    cout << "3 x ONE = " << 3 * myPolynomial::ONE << endl;
    cout << "X x 3  = " << myPolynomial::X * 3 << endl;
    cout << "3 x p4(x) = " << 3 * p4 << " p4(x) x 3 = " << p4 * 3 << endl;
    cout << "0 x p5(x) = " << 0 * p5 << " p5(x) x 5 = " << p5 * 5 << endl;

    // test binary operator +
    cout << "p4(x) + p5(x) = " << p4 + p5 << endl;

    // test binary operator -
    cout << "p6(x) - p7(x) = " << p6 - p7 << endl;

    // test binary operator *
    cout << "p8(x) x p9(x) = " << p8 * p9 << endl;

    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;

    cout << "p4(x) += p5(x) : " << (tmp1 += p5) << endl;
    cout << "p4(x) -= p5(x) : " << (tmp2 -= p5) << endl;
    cout << "p4(x) *= p5(x) : " << (tmp3 *= p5) << endl;
    cout << "p4(x) *= 3 : " << (tmp4 *= 3) << endl;
}

void testDataFromFile(int numTerms) {
    int terms[100];

    /* read first polynomial */
    // cin >> numTerms;
    for (int j = 0; j < numTerms; j++)
        cin >> terms[2 * j] >> terms[2 * j + 1];

    myPolynomial p1(numTerms, terms);

    /* read second polynomial */
    cin >> numTerms;
    for (int j = 0; j < numTerms; j++)
        cin >> terms[2 * j] >> terms[2 * j + 1];

    myPolynomial p2(numTerms, terms);

    cout << "p1(x) = " << p1 << endl << "p2(x) =  " << p2 << endl;
    cout << "the degree of p1(x) is " << p1.getDegree();
    cout << " and the number of terms of p2(x) is " << p2.getNumTerms() << endl;
    cout << "p1'(x) = " << p1.ddx() << endl << "p2'(x) = " << p2.ddx() << endl;
    cout << "p1 == p2 is " << (p1 == p2) << "p1 != p2 is " << (p1 != p2) << endl;
    cout << "p1(1) = " << p1(1) << endl;

    cout << "-p1(x) + p1(x)*2*p2(x) - p2(x)*2 + 3*p1(x) = " << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;

    myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
    p3 += p1;
    p4 -= p2;
    p5 *= p4;
    p5 *= 2;

    cout << "2x(1-p2(x)) + (0 + p1(x)) = " << p5 + p3 << endl;
}
