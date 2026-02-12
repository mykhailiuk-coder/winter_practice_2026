#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

class WorkerAnt {
private:
    double x0, y0, V;
public:
    WorkerAnt(double x_init, double y_init, double speed)
        : x0(x_init), y0(y_init), V(speed) {
    }

    pair<double, double> position(double t) {
        double L = sqrt(x0 * x0 + y0 * y0);
        double t_to = L / V;
        if (t <= t_to) {
            double ratio = t / t_to;
            return { x0 * (1 - ratio), y0 * (1 - ratio) };
        }
        else {
            double ratio = (t - t_to) / t_to;
            return { x0 * ratio, y0 * ratio };
        }
    }
};

class WarriorAnt {
private:
    double xc, yc, R, V;
public:
    WarriorAnt(double center_x, double center_y, double radius, double speed)
        : xc(center_x), yc(center_y), R(radius), V(speed) {
    }

    pair<double, double> position(double t) {
        double omega = V / R;
        return { xc + R * cos(omega * t), yc + R * sin(omega * t) };
    }
};

void worker_thread(WorkerAnt& ant, double sim_time, double dt, pair<double, double>& pos_shared) {
    for (double t = 0; t <= sim_time; t += dt) {
        auto pos = ant.position(t);
        {
            lock_guard<mutex> lock(mtx);
            pos_shared = pos;
        }
        this_thread::sleep_for(chrono::milliseconds(int(dt * 1000)));
    }
}

void warrior_thread(WarriorAnt& ant, double sim_time, double dt, pair<double, double>& pos_shared) {
    for (double t = 0; t <= sim_time; t += dt) {
        auto pos = ant.position(t);
        {
            lock_guard<mutex> lock(mtx);
            pos_shared = pos;
        }
        this_thread::sleep_for(chrono::milliseconds(int(dt * 1000)));
    }
}

int main() {
    WorkerAnt worker1(5.0, 5.0, 1.0);
    WarriorAnt warrior1(0.0, 0.0, 3.0, 1.0);

    double sim_time = 20.0;
    double dt = 1.0;

    pair<double, double> worker_pos, warrior_pos;

    thread t1(worker_thread, ref(worker1), sim_time, dt, ref(worker_pos));
    thread t2(warrior_thread, ref(warrior1), sim_time, dt, ref(warrior_pos));

    cout << "Time\tWorker(x,y)\t\tWarrior(x,y)\n";

    for (double t = 0; t <= sim_time; t += dt) {
        pair<double, double> w_pos, wa_pos;
        {
            lock_guard<mutex> lock(mtx);
            w_pos = worker_pos;
            wa_pos = warrior_pos;
        }

        cout << t << "s\t(" << w_pos.first << ", " << w_pos.second << ")\t("
            << wa_pos.first << ", " << wa_pos.second << ")\n";

        this_thread::sleep_for(chrono::milliseconds(int(dt * 1000)));
    }

    t1.join();
    t2.join();

    return 0;
}
