#ifndef Fuzzy_h
#define Fuzzy_h

#include <iostream>
using namespace std;

#define ERROR 0
#define DERROR 1
#define kiri_opt(nilai,min,opt) (nilai-min)/(opt-min)
#define kanan_opt(nilai,opt,mak) (mak-nilai)/(mak-opt)



class Fuzzy
{
    private:
        int nb, nm, ns, zero, ps, pm, pb, selisih;
        float data_u[7], u[7], du[7], last_error, d_error;
        //data_fuzzy eJarak, eSudut, eBelok;
        int	 rule[7][7] = { 
				  // nb nm ns z  ps pm pb
					{1, 1, 1, 2, 2, 2, 3}, //nb
					{1, 1, 2, 2, 2, 2, 3}, //nm
					{1, 2, 2, 2, 2, 2, 3}, //ns
			    	{1, 1, 2, 3, 4, 5, 0}, //z
					{2, 3, 3, 4, 4, 5, 0}, //ps
					{3, 3, 4, 4, 5, 0, 0}, //pm 
					{4, 4, 4, 5, 5, 0, 0}, //pb
				  };

    public:

        Fuzzy(int nb_, int nm_, int ns_, int zero_, int ps_, int pm_, int pb_, int selisih_) {
            nb = nb_;
            nm = nm_;
            ns = ns_;
            zero = zero_;
            ps = ps_;
            pm = pm_;
            pb = pb_;
            selisih = selisih_;
            cout << "MASUKKK SINIIII" << endl;
        }

        void print () {
            for(int i=0; i<7; i++) cout << "u..[" << i << "] : " << u[i] 
									<< "\t\tdu..[" << i << "] : " << du[i] << endl;
        }



        float getFuzzy(float error) {
            d_error = error - last_error;
            getDegreeMembership(error, ERROR);
            getDegreeMembership(d_error, DERROR);
            interference();
            last_error = error;
            return defuzzy();
        }



        float defuzzy() {
            float pemb = 0, peny = 0;
            float c[7] = { -16, -8, -5.3, 0, 5.3, 8, 16};
            for (int i = 0; i < 7; i++) {
                pemb += (c[i] * data_u[i]);
                peny += data_u[i];
            }
            return pemb / peny;
        }



        void interference(){
            for (int i = 0; i < 7; i++) data_u[i] = 0;
            
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) { 
                    int k;
                    k = rule[i][j];
                    data_u[k] = max(u[k], min(du[i], u[j]));
                }
            }
        }



        void getDegreeMembership(float value, bool activation) {
            if(activation == 0) {
                for(int i=0; i<7; i++)  u[i] = 0;

                if(value <= nb) u[0] = 1;
                else if(value == nm) u[1] = 1;
                else if(value == ns) u[2] = 1;
                else if(value == zero) u[3] = 1;
                else if(value == ps) u[4] = 1;
                else if(value == pm) u[5] = 1;
                else if(value == pb) u[6] = 1;
                else if(value > nb && value < nm){
                    u[0] = kanan_opt(value, nb, (nb + selisih));
                    u[1] = kiri_opt(value, (nm - selisih), nm);
                }
                else if(value > nm && value < ns) {
                    u[1] = kanan_opt(value, nm, (nm + selisih));
                    u[2] = kiri_opt(value, (ns - selisih), ns);
                }
                else if(value > ns && value < zero) {
                    u[2] = kanan_opt(value, ns, (ns + selisih));
                    u[3] = kiri_opt(value, (zero - selisih), zero);
                }
                else if(value > zero && value < ps) {
                    u[3] = kanan_opt(value, zero, (zero + selisih));
                    u[4] = kiri_opt(value, (ps - selisih), ps);
                }
                else if(value > ps && value < pm) {
                    u[4] = kanan_opt(value, ps, (ps + selisih));
                    u[5] = kiri_opt(value, (pm - selisih), pm);
                }
                else if(value > pm && value < pb) {
                    u[5] = kanan_opt(value, pm, (pm + selisih));
                    u[6] = kiri_opt(value, (pb - selisih), pb);
                }
            }

            else if(activation == 1) {
                for(int i=0; i<7; i++)  du[i] = 0;

                if(value <= nb) du[0] = 1;
                else if(value == nm) du[1] = 1;
                else if(value == ns) du[2] = 1;
                else if(value == zero) du[3] = 1;
                else if(value == ps) du[4] = 1;
                else if(value == pm) du[5] = 1;
                else if(value == pb) du[6] = 1;
                else if(value > nb && value < nm){
                    du[0] = kanan_opt(value, nb, (nb + selisih));
                    du[1] = kiri_opt(value, (nm - selisih), nm);
                }
                else if(value > nm && value < ns) {
                    du[1] = kanan_opt(value, nm, (nm + selisih));
                    du[2] = kiri_opt(value, (ns - selisih), ns);
                }
                else if(value > ns && value < zero) {
                    du[2] = kanan_opt(value, ns, (ns + selisih));
                    du[3] = kiri_opt(value, (zero - selisih), zero);
                }
                else if(value > zero && value < ps) {
                    du[3] = kanan_opt(value, zero, (zero + selisih));
                    du[4] = kiri_opt(value, (ps - selisih), ps);
                }
                else if(value > ps && value < pm) {
                    du[4] = kanan_opt(value, ps, (ps + selisih));
                    du[5] = kiri_opt(value, (pm - selisih), pm);
                }
                else if(value > pm && value < pb) {
                    du[5] = kanan_opt(value, pm, (pm + selisih));
                    du[6] = kiri_opt(value, (pb - selisih), pb);
                }
            }
        }


    
};

#endif
