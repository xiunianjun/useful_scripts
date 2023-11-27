import matplotlib.pyplot as plt
import os

path = "./"


class DataProcessing:
    def __init__(self) -> None:
        self.data = []
        self.bridge = None
        with open(os.path.join(path, 'data.txt'), 'r') as f:
            for line in f:
                line = [float(x)/1000 for x in line.split('\t')]
                self.data.append(line)

    def voltage_current_characteristic(self):
        # 绘制第一根线
        plt.plot(self.data[0], self.data[1], label='ghOSt',marker='o')
        # plt.plot(self.data[0], self.data[2], label='COS', marker='x')
        # plt.plot(self.data[0], self.data[3], label='CFS', marker='.')
        
        plt.xlabel('Throughput(1K req/s)')
        plt.ylabel('Latency(us)')
        
        x_scale = min(self.data[0])*0.8, max(self.data[0])*1.15
        # y_scale = 10, 20
        y_scale = min(self.data[1])*0.95, max(self.data[1])*1.05
        plt.axis(x_scale + y_scale)
        
        plt.legend(loc='best')
        plt.savefig(os.path.join(path,"figure_1.png"),dpi=800)
        plt.show()
    def Wheatstone_bridge(self):
        pass

if __name__ == '__main__':
    run = DataProcessing()
    run.voltage_current_characteristic()
    