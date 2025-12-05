const { contextBridge, ipcRenderer } = require('electron');

contextBridge.exposeInMainWorld('audioAPI', {
    startPlayback: () => ipcRenderer.invoke('start-playback'),
    stopPlayback: () => ipcRenderer.invoke('stop-playback')
});
