"use client"
import { createContext, useContext, useState } from 'react';
import timelineComponent from './timeline';
import Viewport from './viewport';

export default function Home() {
  const [timeline, setTimeline] = useState({
    frame: 0,
    framerate: 30,
    videosetting: {
      width: 1920,
      height: 1080,
    },
    track: {
      video: [],
      audio: [],
    }
  });

  return (
    <main className="w-full h-full fixed">
      {Viewport([timeline, setTimeline])}
      {timelineComponent([timeline, setTimeline])}
    </main>
  )
}
