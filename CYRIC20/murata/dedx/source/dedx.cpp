#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <TGraph.h>
#include <TFile.h>

struct particle_profile
{
    particle_profile(){};
    particle_profile(const std::string &_name,
                     const std::string &_file100,
                     const std::string &_file500) : name(_name),
                                                    dedx100(_file100.c_str()),
                                                    dedx500(_file500.c_str())
    {
        dedx100.SetName(std::string(_name + "100").c_str());
        dedx500.SetName(std::string(_name + "500").c_str());
    };

    void Write()
    {
        dedx100.Write();
        dedx500.Write();
    }

    std::pair<double, double> GetdE_E(double _kineE) const
    {
        double de, e;
        de = dedx100.Eval(_kineE);
        double e_remain = _kineE - de;
        if (e_remain < 0.1)
        {
            e = 0;
        }
        else
        {
            e = dedx500.Eval(e_remain);
        }
        return std::make_pair(de, e);
    };

    std::string name;
    TGraph dedx100;
    TGraph dedx500;
};

class dedx_graph_factory
{
public:
    dedx_graph_factory(const std::map<std::string, particle_profile> &_r_particle_list) : r_particle_list(_r_particle_list){};

    TGraph MakeGraph(const std::string &_particle,
                     std::vector<double> &_vKineE)
    {
        auto it = r_particle_list.find(_particle);
        if (it == r_particle_list.end())
        {
            throw std::runtime_error(_particle + " NOT defined.");
        }
        TGraph g(_vKineE.size());
        int iPoint = 0;
        for (auto kE : _vKineE)
        {
            double de, e;
            std::tie(de, e) = it->second.GetdE_E(kE);
            g.SetPoint(iPoint++, de, e);
        }
        return g;
    }

private:
    const std::map<std::string, particle_profile> &r_particle_list;
};

int main()
{
    std::map<std::string, particle_profile> particle_list;
    particle_list.insert(std::make_pair("p", particle_profile("p", "../data/p100.txt", "../data/p500.txt")));
    particle_list.insert(std::make_pair("d", particle_profile("d", "../data/d100.txt", "../data/d500.txt")));
    particle_list.insert(std::make_pair("t", particle_profile("t", "../data/t100.txt", "../data/t500.txt")));
    particle_list.insert(std::make_pair("3He", particle_profile("3He", "../data/3He100.txt", "../data/3He500.txt")));
    particle_list.insert(std::make_pair("a", particle_profile("a", "../data/a100.txt", "../data/a500.txt")));
    particle_list.insert(std::make_pair("6Li", particle_profile("6Li", "../data/6Li100.txt", "../data/6Li500.txt")));
    particle_list.insert(std::make_pair("7Li", particle_profile("7Li", "../data/7Li100.txt", "../data/7Li500.txt")));
    particle_list.insert(std::make_pair("9Be", particle_profile("9Be", "../data/9Be100.txt", "../data/9Be500.txt")));
    particle_list.insert(std::make_pair("10B", particle_profile("10B", "../data/10B100.txt", "../data/10B500.txt")));
    particle_list.insert(std::make_pair("12C", particle_profile("12C", "../data/12C100.txt", "../data/12C500.txt")));
    // particle_list.insert("d", particle_profile("d", "../data/d100.txt", "../data/d500.txt");

    TFile fOut("dedx.root", "recreate");
    std::vector<std::string> particles;
    for (auto &part : particle_list)
    {
        part.second.Write();
        particles.push_back(part.first);
    }

    dedx_graph_factory factory(particle_list);
    std::vector<double> vKineE{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17.5, 20, 25, 30, 40, 50};

    for (auto part : particles)
    {
        auto g = factory.MakeGraph(part, vKineE);
        std::string graphName = "g" + part;
        g.SetName(graphName.c_str());
        g.SetTitle("dE_500 vs dE_100");
        g.Write();
    }
    return 0;
}