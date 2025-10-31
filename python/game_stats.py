"""
GameStats - eSports / Gaming Data Dashboard
Author: Your Name
Description:
A Streamlit + Pandas dashboard to visualize player and team stats
for different games. Includes sample data and clean structure for linting.
"""

import streamlit as st
import pandas as pd
import plotly.express as px


def create_sample_data():
    """Create a sample DataFrame with 10 rows of eSports statistics."""
    data = {
        "player": [
            "Ace", "Blaze", "Shadow", "Nova", "Crimson",
            "Viper", "Frost", "Echo", "Luna", "Phantom"
        ],
        "team": [
            "Falcons", "Inferno", "Titans", "Falcons", "Inferno",
            "Titans", "Falcons", "Inferno", "Titans", "Falcons"
        ],
        "game": [
            "Valorant", "Valorant", "CS:GO", "Valorant", "Valorant",
            "CS:GO", "Valorant", "Valorant", "CS:GO", "Valorant"
        ],
        "kills": [204, 178, 310, 250, 190, 275, 230, 200, 260, 225], 
        "deaths": [98, 110, 190, 120, 130, 150, 115, 100, 160, 120],
        "assists": [65, 80, 120, 95, 70, 110, 90, 85, 100, 75],
        "matches": [25, 22, 30, 26, 21, 28, 27, 23, 29, 25],
        "wins": [18, 15, 21, 19, 13, 20, 17, 16, 22, 18],
        "region": [
            "EU", "NA", "EU", "EU", "NA",
            "EU", "EU", "NA", "EU", "EU"
        ],
        "year": [2023, 2023, 2022, 2023, 2023, 2022, 2023, 2023, 2022, 2023],
    }
    return pd.DataFrame(data)


def display_kpis(filtered_df, selected_game, selected_year):
    """Display key performance indicators for selected filters."""
    st.subheader(f"📊 {selected_game} – {selected_year} Overview")
    col1, col2, col3 = st.columns(3)

    avg_kills = filtered_df["kills"].mean()
    total_matches = filtered_df["matches"].sum()
    total_wins = filtered_df["wins"].sum()
    avg_assists = filtered_df["assists"].mean()
    win_rate = (total_wins / total_matches) * 100 if total_matches else 0

    col1.metric("Average Kills", f"{avg_kills:.1f}")
    col2.metric("Win Rate", f"{win_rate:.1f}%")
    col3.metric("Average Assists", f"{avg_assists:.1f}")


def display_charts(df, filtered_df, selected_team):
    """Display all charts."""
    # Player Performance
    st.subheader("🎯 Player Performance")
    fig = px.bar(
        filtered_df,
        x="player",
        y=["kills", "deaths", "assists"],
        title="Player Stats Comparison",
        barmode="group",
        color_discrete_sequence=["#FF6B6B", "#4ECDC4", "#FFD93D"],
    )
    st.plotly_chart(fig, use_container_width=True)

    # Team Win Rate
    st.subheader("🏆 Team Win Rate Comparison")
    team_stats = (
        filtered_df.groupby("team")[["wins", "matches"]].sum().reset_index()
    )
    team_stats["win_rate"] = (
        team_stats["wins"] / team_stats["matches"]
    ) * 100

    fig2 = px.bar(
        team_stats,
        x="team",
        y="win_rate",
        title="Win Rate by Team",
        color="team",
        text=team_stats["win_rate"].round(1),
    )
    st.plotly_chart(fig2, use_container_width=True)

    # K/D Ratio Over Time
    st.subheader("📈 K/D Ratio Over Time (All Data)")
    df["kd_ratio"] = df["kills"] / df["deaths"]
    trend_df = df[df["team"].isin(selected_team)]
    fig3 = px.line(
        trend_df,
        x="year",
        y="kd_ratio",
        color="team",
        markers=True,
        title="K/D Ratio Trend by Team",
    )
    st.plotly_chart(fig3, use_container_width=True)


def main():
    """Main function to render the Streamlit dashboard."""
    st.set_page_config(page_title="🎮 GameStats Dashboard", layout="wide")
    st.title("🎮 GameStats – eSports Data Dashboard")
    st.markdown("Analyze and visualize player and team performance.")

    df = create_sample_data()

    st.sidebar.header("🔍 Filter Data")
    games = sorted(df["game"].unique())
    selected_game = st.sidebar.selectbox("Select Game", games)

    teams = sorted(df[df["game"] == selected_game]["team"].unique())
    selected_team = st.sidebar.multiselect("Select Teams",
                                           teams, default=teams[:2])

    years = sorted(df["year"].unique())
    selected_year = st.sidebar.selectbox("Select Year", years)

    filtered_df = df[
        (df["game"] == selected_game)
        & (df["team"].isin(selected_team))
        & (df["year"] == selected_year)
    ]

    display_kpis(filtered_df, selected_game, selected_year)
    display_charts(df, filtered_df, selected_team)

    st.markdown("---")
    st.caption("Built with ❤️ using Streamlit & Pandas")


if __name__ == "__main__":
    main()
