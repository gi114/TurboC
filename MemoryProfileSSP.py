from Tkinter import *
import matplotlib.pyplot as plt
import numpy as np


class MemProfile(object):
    """SSP Memory profile representation"""
    def __init__(self):
        self.cardinality = [5, 10, 15, 20, 25, 30, 35]
        self.mem_peak = [7, 7, 7, 7, 7.7, 14.1, 26.2]
        self.addition_accumulated_heap = [0, 1.72, 8.28, 32.96, 141.4, 463.68, 1244.32]
        self.main_accumulated_heap = [1.2, 2.112, 4.432, 12.184, 39.952, 114.744, 278.128]
        self.program_size = [3.584, 3.648, 3.712, 3.776, 3.856, 3.936, 4]

    def getprofile(self):
        plt.plot(self.cardinality, self.mem_peak, 'r--', self.cardinality, self.program_size, 'b--')
        plt.show()

    def trends(self):
        x = np.array(self.cardinality)
        y = np.array(self.addition_accumulated_heap)
        z = np.polyfit(x, y, 3)
        print("{0}x^3 + {1}x^2 + {2}x + {3}").format(*z)


profile = MemProfile()
profile.trends()
