import serial
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.image import Image
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.properties import ObjectProperty, ListProperty
from kivy.lang import Builder
from kivy.animation import Animation
from kivymd.app import MDApp
from kivymd.uix.behaviors import HoverBehavior
from kivy.uix.screenmanager import ScreenManager, Screen
from kivymd.uix.menu import MDDropdownMenu
from kivy.uix.scrollview import ScrollView
import struct

ser = serial.Serial("com4", 115200, timeout=2)
from kivy.core.window import Window
Window.size = (375, 630)

class HomeWindow(Screen):
    pass

class LEDWindow(Screen):
    def red_spinner_clicked(self, value):
        self.ids.led_spinner_r.text = f'{value}'
    def green_spinner_clicked(self, value):
        self.ids.led_spinner_g.text = f'{value}'
    def blue_spinner_clicked(self, value):
        self.ids.led_spinner_b.text = f'{value}'
    def red_button_pressed(self):
        buffer = []
        duration = int(self.ids.redDuration.text)
        duration_in_bytes = duration.to_bytes(2, 'little')
        num_repeats = int(self.ids.redRepeats.text)
        repeats_in_bytes = num_repeats.to_bytes(2, 'little')
        if self.ids.led_spinner_r.text == 'Breathe Up':
            func_code = 'kr'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_r.text == 'Breathe Down':
            func_code = 'lr'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_r.text == 'Breathe Regular':
            func_code = 'mr'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_r.text == 'Flash':
            func_code = 'nr'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_r.text == 'Solid':
            func_code = 'or'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
    
    def green_button_pressed(self):
        buffer = []
        duration = int(self.ids.greenDuration.text)
        duration_in_bytes = duration.to_bytes(2, 'little')
        num_repeats = int(self.ids.greenRepeats.text)
        repeats_in_bytes = num_repeats.to_bytes(2, 'little')
        if self.ids.led_spinner_g.text == 'Breathe Up':
            func_code = 'kg'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_g.text == 'Breathe Down':
            func_code = 'lg'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_g.text == 'Breathe Regular':
            func_code = 'mg'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_g.text == 'Flash':
            func_code = 'ng'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_g.text == 'Solid':
            func_code = 'og'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            ser.write(buffer)
    
    def blue_button_pressed(self):
        buffer = []
        duration = int(self.ids.blueDuration.text)
        duration_in_bytes = duration.to_bytes(2, 'little')
        num_repeats = int(self.ids.blueRepeats.text)
        repeats_in_bytes = num_repeats.to_bytes(2, 'little')
        if self.ids.led_spinner_b.text == 'Breathe Up':
            func_code = 'kb'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_b.text == 'Breathe Down':
            func_code = 'lb'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_b.text == 'Breathe Regular':
            func_code = 'mb'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_b.text == 'Flash':
            func_code = 'nb'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            buffer.extend(repeats_in_bytes)
            ser.write(buffer)
        elif self.ids.led_spinner_b.text == 'Solid':
            func_code = 'ob'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(duration_in_bytes)
            ser.write(buffer)
        
    def byte_send(self):
        buffer = []
        func_code = 'p'.encode('utf-8')
        bps = int(self.ids.blinks_ps.text)
        bps_in_bytes = bps.to_bytes(2, 'little')
        binarycode_text = self.ids.binary_blinks.text
        binarycode_bytes = binarycode_text.encode('utf-8')
        buffer.extend(func_code)
        buffer.extend(bps_in_bytes)
        buffer.extend(binarycode_bytes)
        ser.write(buffer)
        
class PiezoWindow(Screen):
    def piezo_spinner_clicked(self, value):
        self.ids.piezo_spinner.text = f'{value}'
    def piezo_button_pressed(self):
        buffer = []
        repeats = int(self.ids.piezoRepeats.text)
        repeat_in_bytes = repeats.to_bytes(2, 'little')
        if self.ids.piezo_spinner.text == 'Siren':
            func_code = 'a'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Alarm1':
            func_code = 'b'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Alarm2':
            func_code = 'c'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Ascending':
            func_code = 'd'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Descending':
            func_code = 'e'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Chime Netural':
            func_code = 'f'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Chime Negative':
            func_code = 'g'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Chime Positive':
            func_code = 'h'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Chime Notify':
            func_code = 'i'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
        elif self.ids.piezo_spinner.text == 'Battery Chime':
            func_code = 'j'.encode('utf-8')
            buffer.extend(func_code)
            buffer.extend(repeat_in_bytes)
            ser.write(buffer)
    
    def tune_button_pressed(self):
        buffer = []
        notes = self.ids.noteInput.text + " "
        beats = self.ids.beatInput.text
        bpm = int(self.ids.beats_per_min.text)
        func_code = 'q'.encode('utf-8')
        bpm = bpm.to_bytes(2, 'little')
        notes = notes.encode('utf-8')
        beats = beats.split()
        float_beats = []
        buffer.extend(func_code)
        buffer.extend(bpm)
        buffer.extend(notes)
        for b in beats:
            float_beats.append(float(b))
        for fb in float_beats:
            x = bytearray(struct.pack("f", fb))
            buffer.extend(x)
        print(buffer)
        ser.write(buffer)
        
class SettingsWindow(Screen):
    alerts_dict = {"Low Glucose": [0,0,0], "High Glucose": [0,0,0], "Loss of Therapy Protections": [0,0,0], "No SG": [0,0,0], "Manual Suspend": [0,0,0], "Occlusion": [0, 0, 0], "Low Insulin Reservoir":[0,0,0], 
    "Low Insulin Reservoir":[0,0,0], "Over-infusion":[0,0,0], "Lost Controller":[0,0,0], "Low Pump Battery":[0,0,0], "Depleted Battery":[0,0,0], "Critical Pump Error":[0,0,0], "Simple Pump Notification":[0,0,0], "Charging":[0,0,0], "Pairing": [0,0,0]}
    
    piezo_alerts_to_char = {"Siren": 'a', "Alarm1": 'b', "Alarm2": 'c', "Ascending": 'd', "Descending": 'e', "Chime Neutral": 'f', "Chime Negative": 'g', "Chime Positive": 'h', "Chime Notify": 'i', "Battery Chime": 'j'}
    LED_alerts_to_char = {"Breathe Up": 'a', "Breathe Down": 'b', "Breathe Regular": 'c', "Flash": 'd', "Solid": 'e'}
    alerts = ["Low Glucose", "High Glucose", "Loss of Therapy Protections", "No SG", "Manual Suspend", "Occlusion", "Low Insulin Reservoir", 
    "Over-infusion", "Lost Controller", "Low Pump Battery", "Depleted Battery", "Critical Pump Error", "Simple Pump Notification", "Charging", "Pairing"]
    
    def alert_type_p_clicked(self, value):
        self.ids.piezo_alert_type.text = value
        if self.alerts_dict[value][0] != 0:
            self.ids.piezo_choice.text = self.alerts_dict[value][0]
    
    def pzo_spin_clicked(self, value):
        self.ids.piezo_choice.text = value

    def save_piezo(self, alert_type, piezo_mode):
        if piezo_mode != "Piezo Mode":
            self.alerts_dict[alert_type][0] = piezo_mode

    def alert_type_L_clicked(self, value):
        self.ids.LED_alert_type.text = value
        if self.alerts_dict[value][1] != 0:
            self.ids.LED_choice.text = self.alerts_dict[value][1]
        if self.alerts_dict[value][2] != 0:
            self.ids.LED_color_choice.text = self.alerts_dict[value][2]
    
    def LED_spin_clicked(self, value):
        self.ids.LED_choice.text = value
    
    def LED_color_clicked(self, value):
        self.ids.LED_color_choice.text = value

    def save_LED(self, alert_type, LED_mode, LED_color):
        if LED_mode != "LED Mode":
            self.alerts_dict[alert_type][1] = LED_mode
        if LED_color != "Color":
            self.alerts_dict[alert_type][2] = LED_color
    
    def alert_type_t_clicked(self, value):
        self.ids.alert_type_test.text = value
        if self.alerts_dict[value][0] != 0:
            self.alert_type_p_clicked(value)
        if self.alerts_dict[value][1] != 0:
            self.alert_type_L_clicked(value)
        
        
    
    def test_button_pressed(self, alert_val):
        if alert_val == "Alert Type":
            return
        chosen_piezo = self.alerts_dict[alert_val][0]
        chosen_LED_mode = self.alerts_dict[alert_val][1]
        chosen_LED_color = self.alerts_dict[alert_val][2]
        piezo_char = self.piezo_alerts_to_char[chosen_piezo]
        LED_char = self.LED_alerts_to_char[chosen_LED_mode]
        color_char = chosen_LED_color.lower()
        buff = []
        func_code = 'r'.encode('utf-8')
        buff.extend(func_code)
        buff.extend(piezo_char.encode('utf-8'))
        buff.extend(LED_char.encode('utf-8'))
        buff.extend(color_char.encode('utf-8'))
        ser.write(buff)

class WindowManager(ScreenManager):
    pass

class HoverButton(Button, HoverBehavior):
    background = ListProperty((70/255, 70/255, 70/255, 1))
    def on_enter(self):
        self.background = (251/255, 104/255, 23/255, 1)

    def on_leave(self):
        self.background = (70/255, 70/255, 70/255, 1)

class HoverButtonSmall(Button, HoverBehavior):
    background = ListProperty((70/255, 70/255, 70/255, 1))
    def on_enter(self):
        self.background = (251/255, 104/255, 23/255, 1)

    def on_leave(self):
        self.background = (70/255, 70/255, 70/255, 1)

class MyApp(MDApp):
    led_dropdown = ObjectProperty()
    piezo_dropdown = ObjectProperty()
    data_led = {
        "Home": "home",
        "Piezo": "bullhorn",
        "Vibration": "volume-vibrate",
        "Alerts": "alert-circle"
    }
    data_piezo = {
        "Home": "home",
        "LEDs": "alarm-light",
        "Vibration": "volume-vibrate",
        "Alerts": "alert-circle"
    }
    def nav_callback(self, instance):
        if (instance.icon == 'home'):
            self.root.transition.direction = "right"
            self.root.current = "home"
        if (instance.icon == 'bullhorn'):
            self.root.transition.direction = "up"
            self.root.current = "PiezoWnd"
        if (instance.icon == 'alarm-light'):
            self.root.transition.direction = "up"
            self.root.current = "ledWnd"

    def build(self):
        self.title = 'Alerts Demo'
        kv = Builder.load_file("boxdesign.kv")
        return kv

if __name__ == "__main__":
    MyApp().run()