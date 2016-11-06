class Cd
{
	private:
		char performance[50];
		char label[20];
		int selections;
		double playtime;
	public:
		Cd(char * s1, char * s2, int n, double x);
		Cd(const Cd & d);
		Cd();
		virtual ~Cd();
		int getSelections() const {return selections;}
		virtual void Reprot() const;
		Cd & operator=(const Cd & d);
};

class Classic: public Cd
{
	private:
		char** tracknames;
	public:
		Classic(char * s1, char * s2, int n, double x, char **tracknames);
		Classic(const Classic & d);
		Classic();
		virtual ~Classic();
		virtual void Reprot() const;
		Classic & operator=(const Classic & d);

};

