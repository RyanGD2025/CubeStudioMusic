const { app, BrowserWindow, ipcMain } = require('electron');
const path = require('path');

let audioCore;
try {
    audioCore = require('bindings')('audiocore_addon');
} catch (e) {
    audioCore = null;
}

function createWindow () {
  const win = new BrowserWindow({
    width: 1200,
    height: 800,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: false,
      contextIsolation: true
    }
  });

  win.loadFile('index.html');
}

app.whenReady().then(() => {
    createWindow();
    
    if (audioCore) {
        audioCore.initializeAudioEngine(48000, 256);

        ipcMain.handle('start-playback', () => {
            audioCore.startPlayback();
        });

        ipcMain.handle('stop-playback', () => {
            audioCore.stopPlayback();
        });
    }

    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
            createWindow();
        }
    });
});

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});
