function varargout = Guassian_GUI(varargin)
% GUASSIAN_GUI MATLAB code for Guassian_GUI.fig
%      GUASSIAN_GUI, by itself, creates a new GUASSIAN_GUI or raises the existing
%      singleton*.
%
%      H = GUASSIAN_GUI returns the handle to a new GUASSIAN_GUI or the handle to
%      the existing singleton*.
%
%      GUASSIAN_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUASSIAN_GUI.M with the given input arguments.
%
%      GUASSIAN_GUI('Property','Value',...) creates a new GUASSIAN_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Guassian_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Guassian_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Guassian_GUI

% Last Modified by GUIDE v2.5 20-May-2016 19:42:02

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Guassian_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Guassian_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT



% --- Executes just before Guassian_GUI is made visible.
function Guassian_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Guassian_GUI (see VARARGIN)

% Choose default command line output for Guassian_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Guassian_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Guassian_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double
global n;
user_entry = str2double(get(hObject,'string'));
if isnan(user_entry)
    errordlg('You must enter a numeric value','Bad Input','modal')
end
n = user_entry;

% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double
global m;
user_entry = str2double(get(hObject,'string'));
if isnan(user_entry)
    errordlg('You must enter a numeric value','Bad Input','modal')
end
m = user_entry;

% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double
global a;
user_entry = str2double(get(hObject,'string'));
if isnan(user_entry)
    errordlg('You must enter a numeric value','Bad Input','modal')
end
a = user_entry;

% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double
global w;
user_entry = str2double(get(hObject,'string'));
if isnan(user_entry)
    errordlg('You must enter a numeric value','Bad Input','modal')
end
w = user_entry;

% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in EI.
function EI_Callback(hObject, eventdata, handles)
% hObject    handle to EI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global n m a w;
figure();
ElectricIndensity(n,m,a,w);

% --- Executes on button press in PD.
function PD_Callback(hObject, eventdata, handles)
% hObject    handle to PD (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global n m a w;
figure();
PhaseDistribution(n,m,a,w);

% --- Executes on button press in LI.
function LI_Callback(hObject, eventdata, handles)
% hObject    handle to LI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global n m a w;
figure();
LightIndensity(n,m,a,w);
  
% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global n m a w;
n = 1;
m = 0;
a = 1;
w = 1;

% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global n m a w;
figure;
lp01_change(n,m,a,w);

function ElectricIndensity(n,m,a,w)
% LPnma的电场强度
% n     径向
% m     圆周
% a     简并，默认值为1。1代表LPnma，2代表LPnmb
% w     高斯光斑半径，默认值为1


xx = linspace(-7.68,7.68,1920);
yy = linspace(-4.32,4.32,1080);
%xx = linspace(-13.3,13.3,832);
%yy = linspace(-10,10,624);
[x y] = meshgrid(xx,yy);

[E I fai] = LaguerreGuassian(n,m,x,y,a,w);

mesh(x,y,E);
colormap jet
hold on
if a==1
    title(['LP_' num2str(m) '_' num2str(n) '_' 'a']);
else
    title(['LP_' num2str(m) '_' num2str(n) '_' 'b']);
end
hold on

function LightIndensity(n,m,a,w)
% LPnma的光强图（光斑）
% n     径向
% m     圆周
% a     简并，默认值为1。1代表LPnma，2代表LPnmb
% w     高斯光斑半径，默认值为1


xx = linspace(-7.68,7.68,1920);
yy = linspace(-4.32,4.32,1080);
[x y] = meshgrid(xx,yy);

[E I fai] = LaguerreGuassian(n,m,x,y,a,w);

surf(x,y,I);
shading interp;
axis equal;
axis([-3*w,3*w,-3*w,3*w]);
box on;
axis off;
hold on;
if a==1
    title(['LP_' num2str(m) '_' num2str(n) '_' 'a']);
else
    title(['LP_' num2str(m) '_' num2str(n) '_' 'b']);
end
% title(['LP_' num2str(m) '_' num2str(n) '_' num2str(a)]);      

function PhaseDistribution(n,m,a,w)
% LPnma的相位分布
% n     径向,n默认值为1
% m     圆周，m的默认值为0
% a     简并，默认值为1。1代表LPnma，2代表LPnmb
% w     高斯光斑半径，默认值为1


xx = linspace(-7.68,7.68,1920);
yy = linspace(-4.32,4.32,1080);
[x y] = meshgrid(xx,yy);

[E I fai] = LaguerreGuassian(n,m,x,y,a,w);

imshow(fai);
if a==1
    imwrite(fai./pi/2,['lp' num2str(m) num2str(n)  'a.jpg'],'jpg');
else
    imwrite(fai./pi/2,['lp' num2str(m) num2str(n)  'b.jpg'],'jpg');
end

box on;
axis off;
hold on;
% title(['LP_' num2str(m) '_' num2str(n) '_' num2str(a)]);
if a==1
    title(['LP_' num2str(m) '_' num2str(n) '_' 'a']);
else
    title(['LP_' num2str(m) '_' num2str(n) '_' 'b']);
end

function lag = laguerre(n,m,x)
% This function is used to produce Laguerre polynomarial with order of n.

lag = zeros(size(x));
 f_nm = factorial(n+m);
% f_mk = factorial(m);
% f_k = 1;
% f_nk = factorial(n);
for k = 0:n
    f_mk = factorial(m+k);
    f_k = factorial(k);
    f_nk = factorial(n-k);
    
    lag = lag + f_nm.*(-x).^k/(f_mk*f_k*f_nk);
end

function [Ee Ie fai] = LaguerreGuassian(n,m,x,y,a,w)
% This function is used to produce Laguerre Guassian with order of n and m.

% input
% n and m mean the order of LP_nm.
% x y           argument
% a      degenerate of LP_nm, and a = 1 means LP_nma,a = 2 means LP_nmb.
% w      The waist of Guassian beam
% 
%
%output
%Ee     electric intensity
%Ie     light intensity
%fai    phase of electric intensity

[Theta R] = cart2pol(x,y);

if a == 1
    Ee = 1/w*(R*sqrt(2)/w).^m.*laguerre(n-1,m,2*R.^2/w^2).*exp(-R.^2/w^2).*cos(m*Theta);
else
    Ee = 1/w*(R*sqrt(2)/w).^m.*laguerre(n-1,m,2*R.^2/w^2).*exp(-R.^2/w^2).*sin(m*Theta);
end
Ie = abs(Ee).^2;
fai = angle(Ee);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function lp01_change(n,m,a,w)
% LPmn模式的仿真生成---方法：基模高斯的傅里叶变换、SLM相位替换、傅里叶反变换
% n     径向
% m     圆周
% a     简并，默认值为1。1代表LPnma，2代表LPnmb
% w     高斯光斑半径，默认值为1


xx = linspace(-7.68,7.68,1920);
yy = linspace(-4.32,4.32,1080);
[x y] = meshgrid(xx,yy);

[E I fai] = LaguerreGuassian(1,0,x,y,1,w);    %产生初始基模高斯分布 ？
fai_change = faiChange(n,m,a,w);              %获得LPmn模式相位分布
E_fft = fft2(E);                              %经过透镜1
circleRf = circle(x,y,1.5*w);                 %加一个circle函数
%E_fftchange = abs(E_fft).*exp(1i*fai_change); %经过SLM
E_fftchange = 1.*exp(1i*fai_change).*circleRf; %经过SLM  点光源近似

E_ifft = fftshift(fft2(E_fftchange));          %经过透镜2
E_i = abs(E_ifft).^2;                         
fai_i = angle(E_ifft);                        

%经过傅变及相位调整后的光强图（光斑）
surf(x,y,E_i);
shading interp;
axis equal;
axis([-0.1*w,0.1*w,-0.1*w,0.1*w]);
box on;
axis off;
hold on;
if a==1
    title(['LP_' num2str(m) '_' num2str(n) '_' 'a--simulation']);
else
    title(['LP_' num2str(m) '_' num2str(n) '_' 'b--simulation']);
end

figure;

%经过傅变及相位调整后的相位图
imshow(fai_i);
box on;
axis off;
hold on;
if a==1
    title(['LP_' num2str(m) '_' num2str(n) '_' 'a--simulation']);
else
    title(['LP_' num2str(m) '_' num2str(n) '_' 'b--simulation']);
end

function fai_change = faiChange(n,m,a,w)
% slm的相位变换T函数
% n     径向
% m     圆周
% a     简并，默认值为1。1代表LPnma，2代表LPnmb
% w     高斯光斑半径，默认值为1


xx = linspace(-7.68,7.68,1920);
yy = linspace(-4.32,4.32,1080);
[x y] = meshgrid(xx,yy);

[E I fai] = LaguerreGuassian(n,m,x,y,a,w);
fai_change = fai;

%circle函数
function circle_Rf = circle(x,y,Rf)

[Theta R] = cart2pol(x,y);
circle_Rf = heaviside(Rf*ones(size(R))-R);


% --- Executes during object creation, after setting all properties.
function pushbutton9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
