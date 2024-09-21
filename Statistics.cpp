#include <iostream>
#include <cmath>
using namespace std;

class input {
public:
    int a;
    int sum;
    int noofdata;
    int sdsum;
    int data[50];   
    int frequency[50]; 
    int cumfreq[50]; 

    input() {
        sum = 0;
        noofdata = 0;
        sdsum = 0;
    }

    void getsize() {
        cout << "Enter the size of the data that you've got: " << endl;
        cin >> a;
    }

    void size() {
        getsize();
        cout << "Now enter the data: " << endl;
        for (int i = 0; i < a; ++i) {
            cin >> data[i];
        }
    }

    void getfrequency() {
        cout << "Enter the frequency of the data: " << endl;
        for (int i = 0; i < a; ++i) {
            cin >> frequency[i];
        }
        cout << endl;
    }

    void sort() {
        size();
        getfrequency();
        for (int i = 0; i < a - 1; i++) {
            for (int j = 0; j < a - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                    swap(frequency[j], frequency[j + 1]);
                }
            }
        }
    }

    void meancalc() {
        sort();
        for (int i = 0; i < a; ++i) {
            sum += data[i] * frequency[i];
            sdsum += data[i] * data[i] * frequency[i];
            noofdata += frequency[i];
            cumfreq[i] = noofdata; 
        }
        for (int i = 0; i < a; ++i) {
            cout << data[i] << " (Frequency: " << frequency[i] << ")" << " c.f =" << cumfreq[i] << endl;
        }
    }
};

class mean : public input {
public:
    double avg;

    void calcavg() {
        meancalc();
        avg = static_cast<double>(sum) / noofdata;
        cout << "The mean of the data is " << avg << endl;
        cout << endl;
    }
};

class stadev : public mean {
public:
    double stand;
    double variance; 

    stadev() {
        variance = 0;
        stand = 0;
    }

    void calcstand() {
        variance = static_cast<double>(sdsum) / noofdata - (avg * avg);
        stand = sqrt(variance); 
    }

    void displaystd() {
        calcstand();
        cout << "The Standard deviation of the following data is : " << stand << endl;
    }
};

class quartile : public input {
public:
    int q;
    int placement;

    double calcquartile(int quart, int totalparts) {
        if (quart > totalparts) {
            cout << "Error 104" << endl;
            return 0;
        } else {
            placement = static_cast<int>(static_cast<double>(quart) / totalparts * noofdata);

            for (int i = 0; i < a; ++i) {
                if (cumfreq[i] >= placement) {
                    q = data[i];
                    break;
                }
            }
            return q;
        }
    }
};

class kp : public quartile, public stadev {
public:
    double bowleys_coeff;

    void calkp() {
        double coeff = 3 * (avg - calcquartile(2, 4));
        bowleys_coeff = coeff / stand;
    }

    void showkp() {
        calkp();
        cout << "The Bowleys coefficient of the data is " << bowleys_coeff << endl;
        if (bowleys_coeff > 0) {
            cout << "The data has positive skewness" << endl;
        } else if (bowleys_coeff == 0) {
            cout << "The data has no skewness" << endl;
        } else {
            cout << "The data has negative skewness" << endl;
        }
    }
};

class bowleys : public quartile {
public:
    double bowley_coeff;
    double kurtosis;

    void findbow() {
        bowley_coeff = (calcquartile(3, 4) + calcquartile(1, 4) - 2 * calcquartile(2, 4)) /
                       (calcquartile(3, 4) - calcquartile(1, 4));
    }

    void showbowley() {
        cout << "The Bowleys coefficient of the data is " << bowley_coeff << endl;

        if (bowley_coeff > 0) {
            cout << "The data has positive skewness" << endl;
        } else if (bowley_coeff == 0) {
            cout << "The data has no skewness" << endl;
        } else {
            cout << "The data has negative skewness" << endl;
        }
    }

    void findkurtosis() {
        kurtosis = (calcquartile(3, 4) - calcquartile(1, 4)) / 
                   (2 * (calcquartile(90, 100) - calcquartile(10, 100)));
    }

    void displaykurtosis() {
        findkurtosis();
        cout << "The kurtosis of the following data is : " << kurtosis << endl;
        if (kurtosis > 0.263) {
            cout << "The data has positive kurtosis" << endl;
        } else if (kurtosis == 0) {
            cout << "The data has no kurtosis" << endl;
        } else {
            cout << "The data has negative kurtosis" << endl;
        }
    }
};

int main() {
    cout << "The program can find the kurtosis, skewness, standard deviation, mean, and the mean deviation of continuous data." << endl;

    int inp;
    while (true) {
        cout << "What property do you want to find?" << endl;
        cout << "1. Mean\n2. Standard deviation\n3. Quartiles, deciles, or percentiles\n4. Kurtosis\n5. Skewness\n";
        cin >> inp;

        if (inp == 1) {
            mean m1;
            m1.calcavg();
        } else if (inp == 2) {
            stadev m1;
            m1.calcavg();
            m1.calcstand();
            m1.displaystd();
        } else if (inp == 3) {
            int dec, nth;
            cout << "Press 4 for quartile, 10 for decile, 100 for percentile: ";
            cin >> dec;
            cout << "Enter the th value you want to calculate: ";
            cin >> nth;
            quartile m1;
            m1.sort();
            cout << "The result is: " << m1.calcquartile(nth, dec) << endl;
        } else if (inp == 4) {
            bowleys m1;
            m1.sort();
            m1.findkurtosis();
            m1.displaykurtosis();
        } else if (inp == 5) {
            int sps;
            cout << "Press 1 for Bowleys, 2 for Karl Pearson: ";
            cin >> sps;
            if (sps == 1) {
                bowleys m1;
                m1.sort();
                m1.findbow();
                m1.showbowley();
            } else if (sps == 2) {
                kp m1;
                m1.calcavg();
                m1.calcstand();
                m1.showkp();
            }
        } else {
            cout << "Invalid input, try again." << endl;
        }
    }

    return 0;
}